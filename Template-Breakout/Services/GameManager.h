#pragma once

#include "Singleton.h"
#include <SFML/Graphics.hpp>
#include <list>

class GameManager : public Singleton<GameManager>
{
	friend class Singleton<GameManager>;

private:

	GameManager(); // Constructeur privé
	~GameManager();

public:
	void InitGame(int argc, char* argv[]);
	bool Run();
	bool MainLoop();
	void Update();
	void Draw();
	void EndGame();

	sf::Vector2u GetWindowSize() const { return window.getSize(); }
	sf::RenderWindow* GetWindow() { return &window; }

protected:

	sf::RenderWindow window;

	std::list<std::unique_ptr<GameObject>> mGameObjects;

};
