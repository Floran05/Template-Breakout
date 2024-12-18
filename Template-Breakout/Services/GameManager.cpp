#include "GameManager.h"

#include "../Objects/GameObject.h"
#include "../Services/TimeManager.h"
#include "../Services/InputManager.h"
#include "../Components/CircleShapeComponent.h"
#include "../Components/RectShapeComponent.h"
#include "../Components/MovementComponent.h"
#include "../Components/PaddleControlComponent.h"
#include "../Components/TransformComponent.h"

#include "../resources.h"

GameManager::GameManager()
{
	window.create(sf::VideoMode(WIN_SIZE), WIN_TITLE, sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(FRAMERATE_LIMIT);
}

bool GameManager::Run()
{
	InitGame();
	return MainLoop();
}

void GameManager::InitGame()
{
	std::unique_ptr<GameObject> benBall = std::make_unique<GameObject>();
	benBall->AddComponent<CircleShapeComponent>(BALL_SPRITE_PATH, 25.f);
	benBall->AddComponent<MovementComponent>(sf::Vector2f(0.5f, 0.5f));

	mGameObjects.push_back(std::move(benBall));

	std::unique_ptr<GameObject> paddle = std::make_unique<GameObject>();
	paddle->Transform->Position = { 650.f, 650.f };
	paddle->Transform->Scale = { 0.3f, 0.3f };
	paddle->AddComponent<RectShapeComponent>(PADDLE_SPRITE_PATH, sf::Vector2f(200.f, 50.f));
	paddle->AddComponent<MovementComponent>(sf::Vector2f(0.f, 0.f), 300.f);
	paddle->AddComponent<PaddleControlComponent>();

	mGameObjects.push_back(std::move(paddle));
}

bool GameManager::MainLoop()
{
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
	for (auto it = mGameObjects.begin(); it != mGameObjects.end(); ++it)
	{
		(*it)->Update();
	}
	I(TimeManager)->Update();
}

void GameManager::Draw()
{
  window.clear();
  
	for (auto it = mGameObjects.begin(); it != mGameObjects.end(); ++it)
	{
		(*it)->Draw();
	}
  
  window.display();
}


void GameManager::ExitGame()
{
	mGameObjects.clear();
	mGameObjects.resize(0);
}


GameManager::~GameManager()
{
	ExitGame();
}