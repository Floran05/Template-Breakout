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

}

bool GameManager::MainLoop()
{
	GameObject* ben = new GameObject();
	// ben->AddComponent<ShapeComponent>(BALL_SPRITE_PATH);
	ben->AddComponent<MovementComponent>(sf::Vector2f(0.5f, 0.5f));

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();
		ben->Update();
		I(TimeManager)->Update();
		window.display();
	}	
	return EXIT_SUCCESS;
}

void GameManager::Update()
{
}

void GameManager::Draw()
{

}


void GameManager::EndGame()
{

}


GameManager::~GameManager()
{

}