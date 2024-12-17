#include "GameManager.h"
#include "../Objects/GameObject.h"
#include "../Services/TimeManager.h"
#include "../Components/ShapeComponent.h"
#include "../Components/MovementComponent.h"
#include "../resources.h"

GameManager::GameManager()
{
	window.create(sf::VideoMode(WIN_SIZE, 24), WIN_TITLE);
	window.setFramerateLimit(60);
}

bool GameManager::Run()
{
	return MainLoop();
}

void GameManager::InitGame(int argc, char* argv[])
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
		window.clear();
		Draw();
		window.display();
	}	
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
	for (auto it = mGameObjects.begin(); it != mGameObjects.end(); ++it)
	{
		(*it)->Draw();
	}
}


void GameManager::EndGame()
{

}


GameManager::~GameManager()
{

}