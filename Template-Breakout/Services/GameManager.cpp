#include "GameManager.h"

#include "../Objects/GameObject.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SpawnerManager.h"
#include "DebugManager.h"

#include "../Components/TransformComponent.h"

#include "../resources.h"
#include "../Components/RectShapeComponent.h"

#include <Windows.h>

GameManager::GameManager()
	: mGamePoints(0)
{
	m_eGameState = ENoneState;
	window.create(sf::VideoMode(WIN_SIZE), WIN_TITLE, sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(FRAMERATE_LIMIT);

	mDefaultFont = sf::Font(DEFAULT_FONT_PATH);
}

bool GameManager::Run()
{
	InitGame();
	return MainLoop();
}

void GameManager::InitGame()
{
	I(SpawnerManager)->Start();

	std::shared_ptr<GameObject> benBall = I(SpawnerManager)->CreateBall({ 650.f, 600.f }, { 0.2f, -1.f }, BALL_RADIUS, 500.f);
	AddGameObject(benBall);

	std::shared_ptr<GameObject> paddle = I(SpawnerManager)->CreatePaddle({ 650.f, 650.f }, 1000.f);
	AddGameObject(paddle);

	music.setLooping(true);
	m_eGameState = EPlayingState;
	music.setVolume(100.f);
}

bool GameManager::MainLoop()
{
	music.play();

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		Update();
		Draw();
	}

	ExitGame();
	return EXIT_SUCCESS;
}

void GameManager::Update()
{  
	I(InputManager)->Update();
	for (GameObjectList::iterator it = mGameObjects.begin(); it != mGameObjects.end(); ++it)
	{
		(*it)->Update();
	}

	if (m_eGameState == EGameOverState && I(InputManager)->IsKeyPressed(VK_SPACE))
		RestartGame();

	I(TimeManager)->Update();
}

void GameManager::Draw()
{
	window.clear();
  
	for (GameObjectList::iterator it = mGameObjects.begin(); it != mGameObjects.end(); ++it)
	{
		(*it)->Draw();
	}

	GameManager::DisplayText(std::to_string(I(TimeManager)->GetApproxFrameRate()), { 20.f, 20.f }, sf::Color::Green);
	DisplayText(std::to_string(mGamePoints), { WIN_WIDTH * 0.5f, 20.f }, sf::Color::Red, true, 50);

#ifdef _DEBUG
	I(DebugManager)->Update();
#endif // _DEBUG

	if (m_eGameState == EIsGoingToGameOverState)
	{
		ShowGameOver();
		m_eGameState = EGameOverState;
	}

	window.display();

	// Clear destroyed elements
	for (GameObjectList::iterator it = mGameObjects.begin(); it != mGameObjects.end();)
	{
		if ((*it)->IsPendingKill())
		{
			it = mGameObjects.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void GameManager::SetIsGameOver(bool isGameOver)
{
	if (isGameOver)
		m_eGameState = EIsGoingToGameOverState;
}

void GameManager::ShowGameOver()
{
	std::shared_ptr<GameObject> background = std::make_shared<GameObject>();
	background->AddComponent<RectShapeComponent>("", sf::Vector2f(WIN_WIDTH, WIN_HEIGHT));
	background->GetComponent<RectShapeComponent>()->GetShape()->setFillColor(sf::Color(0, 0, 0, 200));

	AddGameObject(background);

	std::shared_ptr<GameObject> gameOver = std::make_shared<GameObject>();
	gameOver->AddComponent<RectShapeComponent>(GAMEOVER_SPRITE_PATH, sf::Vector2f(600, 300));
	gameOver->Transform->Position = sf::Vector2f((WIN_WIDTH-600)/2, (WIN_HEIGHT-300)/2);
	AddGameObject(gameOver);

	music.setVolume(10.f);
}

void GameManager::RestartGame()
{
	mGamePoints = 0; 
	I(SpawnerManager)->ClearGrid();
	mGameObjects.clear();
	InitGame();
}


void GameManager::ExitGame()
{
	music.stop();
	mGameObjects.clear();
	mGameObjects.resize(0);
}

void GameManager::AddGameObject(std::shared_ptr<GameObject> object)
{
	mGameObjects.emplace_back(object);
}

void GameManager::DisplayText(const sf::String& text, const sf::Vector2f& position, const sf::Color& color, bool horizontalCenter, const unsigned int fontSize)
{
	sf::Text textObject(mDefaultFont, text);
	textObject.setCharacterSize(fontSize); // Taille en pixels
	textObject.setFillColor(color); // Couleur du texte
	textObject.setStyle(sf::Text::Regular);
	if (horizontalCenter)
	{
		const sf::FloatRect bounds = textObject.getLocalBounds();
		textObject.setPosition({ position.x - bounds.size.x * 0.5f, position.y });
	}
	else
	{
		textObject.setPosition(position);
	}
	window.draw(textObject);
}

GameManager::~GameManager()
{
	ExitGame();
}