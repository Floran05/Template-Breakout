#include "GameManager.h"

#include "../Objects/GameObject.h"
#include "../Services/TimeManager.h"
#include "../Components/ShapeComponent.h"
#include "../Components/MovementComponent.h"

#include "../Objects/Paddle.h"
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
	std::unique_ptr<GameObject> benBall = std::make_unique<GameObject>();
	// benBall->AddComponent<CircleShape>(BALL_SPRITE_PATH);
	// benBall->AddComponent<MovementComponent>();
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
	// Clean here
}


GameManager::~GameManager()
{
	ExitGame();
}