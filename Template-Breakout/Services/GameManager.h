#pragma once

#include "Singleton.h"
#include <SFML/Graphics.hpp>

class GameManager : public Singleton<GameManager>
{
	friend class Singleton<GameManager>;

private:

	GameManager(); // Constructeur privé

public:
	void InitGame(int argc, char* argv[]);
	void Run();
	void MainLoop();
	void Update();
	void Draw();
	void EndGame();

	~GameManager();

	sf::RenderWindow window;
	sf::CircleShape shape;
};
