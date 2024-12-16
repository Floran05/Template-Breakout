#include "GameManager.h"


GameManager* GameManager::instance = nullptr;


GameManager::GameManager()
{
	window.create(sf::VideoMode({ 200, 200 }, 24), "SFML works!");
	window.setFramerateLimit(60);
	shape.setRadius(100.0f);
	shape.setFillColor(sf::Color::Green);
}

GameManager& GameManager::Instance() {
	if (!instance) {
		instance = new GameManager();
	}
	return *instance;
}

void GameManager::Run()
{
	MainLoop();
}


void GameManager::InitGame(int argc, char* argv[])
{
	
}

void GameManager::MainLoop()
{
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}	
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