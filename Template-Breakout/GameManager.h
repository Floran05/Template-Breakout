#pragma once

#include <SFML/Graphics.hpp>

class GameManager
{
private:
	static GameManager* instance;  // Singleton instance

	GameManager(); // Constructeur privé

public:
	// Singleton instance
	static GameManager& Instance();


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
