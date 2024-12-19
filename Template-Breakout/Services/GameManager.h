﻿#pragma once

#include "Singleton.h"
#include <SFML/Graphics.hpp>
#include <list>

#include "../Objects/GameObject.h"

#include <SFML/Audio.hpp>
#include "../resources.h"

enum GameState
{
	ENoneState = 0,
	EPlayingState,
	EIsGoingToGameOverState,
	EGameOverState
};

class GameManager : public Singleton<GameManager>
{
	friend class Singleton<GameManager>;

private:

	GameManager(); // Constructeur privé
	~GameManager();

	sf::Music music = sf::Music(MUSIC_AUDIO);
	std::unique_ptr<sf::Sound> m_GameOverSound;

public:
	void InitGame();
	bool Run();
	bool MainLoop();
	void Update();
	void Draw();

	void SetIsGameOver(bool isGameOver = true);
	void ShowGameOver();
	void RestartGame();

	GameState GetGameState() const { return m_eGameState; }
	bool IsGameState(const GameState& gameState) const { return m_eGameState == gameState; }

	void ExitGame();

	void AddGameObject(std::shared_ptr<GameObject> object);
	void DisplayText(const sf::String& text, const sf::Vector2f& position, const sf::Color& color, bool horizontalCenter = false, const unsigned int fontSize = 30);

	void IncreaseScore() { ++mGamePoints; }
	void ResetScore() { mGamePoints = 0; }

	sf::Vector2u GetWindowSize() const { return window.getSize(); }
	sf::RenderWindow* GetWindow() { return &window; }

	const GameObjectList& GetObjectList() const { return mGameObjects; }
protected:
	sf::RenderWindow window;
	GameObjectList mGameObjects;

	int mGamePoints;

	GameState m_eGameState;
	sf::Font mDefaultFont;
};
