#pragma once

#include "Singleton.h"
#include <SFML/Graphics.hpp>
#include <list>

#include "../Objects/GameObject.h"

#include "SFML/Audio/Music.hpp"
#include "../resources.h"


class GameManager : public Singleton<GameManager>
{
	friend class Singleton<GameManager>;

private:

	GameManager(); // Constructeur privé
	~GameManager();

	sf::Music music = sf::Music(MUSIC_AUDIO);

public:
	void InitGame();
	bool Run();
	bool MainLoop();
	void Update();
	void Draw();
	void ExitGame();

	void AddGameObject(std::shared_ptr<GameObject> object);
	void DrawText(const sf::String& text, const sf::Vector2f& position, const sf::Color& color, bool horizontalCenter = false, const unsigned int fontSize = 30);

	void IncreaseScore() { ++mGamePoints; }
	void ResetScore() { mGamePoints = 0; }

	sf::Vector2u GetWindowSize() const { return window.getSize(); }
	sf::RenderWindow* GetWindow() { return &window; }

	const GameObjectList& GetObjectList() const { return mGameObjects; }
protected:
	sf::RenderWindow window;
	GameObjectList mGameObjects;

	int mGamePoints;

	sf::Font mDefaultFont;
};
