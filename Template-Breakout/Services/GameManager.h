#pragma once

#include "Singleton.h"
#include <SFML/Graphics.hpp>
#include <list>

#include "../Objects/GameObject.h"


class GameManager : public Singleton<GameManager>
{
	friend class Singleton<GameManager>;

private:

	GameManager(); // Constructeur privé
	~GameManager();

public:
	void InitGame();
	bool Run();
	bool MainLoop();
	void Update();
	void Draw();
	void ExitGame();

	void AddGameObject(std::shared_ptr<GameObject> object);

	sf::Vector2u GetWindowSize() const { return window.getSize(); }
	sf::RenderWindow* GetWindow() { return &window; }

protected:
	sf::RenderWindow window;

	std::list<std::shared_ptr<GameObject>> mGameObjects;

};
