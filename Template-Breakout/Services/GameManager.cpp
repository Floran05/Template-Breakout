#include "GameManager.h"

#include "../Objects/GameObject.h"
#include "../Services/TimeManager.h"
#include "../Services/InputManager.h"
#include "../Services/SpawnerManager.h"

#include "../Components/TransformComponent.h"

#include "../resources.h"

#include <iostream>

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
	I(SpawnerManager)->Start();

	std::shared_ptr<GameObject> benBall = I(SpawnerManager)->CreateBall({ 650.f, 600.f }, { 0.f, -1.f }, 25.f, 500.f);
	AddGameObject(benBall);

	std::shared_ptr<GameObject> paddle = I(SpawnerManager)->CreatePaddle({ 650.f, 650.f }, 1000.f);
	AddGameObject(paddle);
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
	for (GameObjectList::iterator it = mGameObjects.begin(); it != mGameObjects.end(); ++it)
	{
		(*it)->Update();
	}
	I(TimeManager)->Update();
}

void GameManager::Draw()
{
	window.clear();
  
	for (GameObjectList::iterator it = mGameObjects.begin(); it != mGameObjects.end(); ++it)
	{
		(*it)->Draw();
	}
	const sf::Font font(DEFAULT_FONT_PATH);
	sf::Text text(font, std::to_string(I(TimeManager)->GetFrameRate()));
	text.setCharacterSize(30);      // Taille en pixels
	text.setFillColor(sf::Color::Green); // Couleur du texte
	text.setStyle(sf::Text::Bold);
	text.setPosition({ 20.f, 20.f });
	window.draw(text);
	window.display();

	// Clear destroyed elements
	for (GameObjectList::iterator it = mGameObjects.begin(); it != mGameObjects.end();)
	{
		if ((*it)->IsPendingKill())
		{
			std::cout << (*it).use_count() << std::endl;
			it = mGameObjects.erase(it);
		}
		else
		{
			++it;
		}
	}
}


void GameManager::ExitGame()
{
	mGameObjects.clear();
	mGameObjects.resize(0);
}

void GameManager::AddGameObject(std::shared_ptr<GameObject> object)
{
	mGameObjects.emplace_back(object);
}


GameManager::~GameManager()
{
	ExitGame();
}