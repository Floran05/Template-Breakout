#include "GameManager.h"
#include "../Objects/Paddle.h"
#include "../Components/SpriteComponent.h"
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
	ball = new GameObject();
	ball->AddComponent<SpriteComponent>(BALL_SPRITE_PATH);

	paddle = new Paddle();
	paddle->AddComponent<SpriteComponent>(PADDLE_SPRITE_PATH);
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
	ball->Update();
	paddle->Update();
}

void GameManager::Draw()
{
	window.clear();

	ball->Draw();
	paddle->Draw();

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