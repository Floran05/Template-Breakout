#include "GameManager.h"

#include "../Objects/GameObject.h"
#include "../Services/TimeManager.h"
#include "../Services/InputManager.h"
#include "../Services/SpawnerManager.h"

#include "../resources.h"

GameManager::GameManager()
{
	window.create(sf::VideoMode(WIN_SIZE), WIN_TITLE);
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

	std::shared_ptr<GameObject> benBall = I(SpawnerManager)->CreateBall({ 100.f, 100.f }, { 0.5f, 0.5f }, 25.f);
	AddGameObject(benBall);

	std::shared_ptr<GameObject> paddle = I(SpawnerManager)->CreatePaddle({ 650.f, 650.f }, 300.f);
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

void GameManager::AddGameObject(std::shared_ptr<GameObject> object)
{
	mGameObjects.emplace_back(object);
}


GameManager::~GameManager()
{
	ExitGame();
}