#include "GameManager.h"
#include "../Objects/GameObject.h"
#include "../Services/TimeManager.h"
#include "../Components/CircleShapeComponent.h"
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
	ben->AddComponent<CircleShapeComponent>(BALL_SPRITE_PATH, 25.f);
	ben->AddComponent<MovementComponent>(sf::Vector2f(0.5f, 0.5f));

	sf::Texture texture;
	texture.loadFromFile(BALL_SPRITE_PATH);
	texture.setSmooth(true);
	sf::CircleShape circleShape(25.f);
	circleShape.setTexture(&texture);
	circleShape.setPosition(sf::Vector2f(200.f, 50.f));
	circleShape.setOrigin(sf::Vector2f(25.f, 25.f));

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();
		ben->Update();
		window.draw(circleShape);
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