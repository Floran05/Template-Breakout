#pragma once

#include "Singleton.h"
#include <SFML/Graphics.hpp>

class GameManager : public Singleton<GameManager>
{
	friend class Singleton<GameManager>;

private:

	GameManager(); // Constructeur privé
	~GameManager();

public:
	void InitGame(int argc, char* argv[]);
	void Run();
	void MainLoop();
	void Update();
	void Draw();
	void EndGame();

	sf::Vector2u GetWindowSize() const { return window.getSize(); }

protected:

	sf::RenderWindow window;
	sf::CircleShape shape;
};
