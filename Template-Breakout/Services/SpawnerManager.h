#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <random>

#include "../Services/Singleton.h"
#include "../resources.h"

class GameObject;
class Brick;

class SpawnerManager : public Singleton<SpawnerManager>
{
	friend class Singleton<SpawnerManager>;
private:

	SpawnerManager();
	virtual ~SpawnerManager();

protected:

	sf::Vector2f mBrickSize;

	std::array<std::array<bool, BRICK_COLUMNS_COUNT>, BRICK_ROWS_COUNT> mGrid;
	bool mIsInGrowPhase;

	std::mt19937 mRandomGenerator;

public:

	std::shared_ptr<GameObject> CreateBrick(const sf::Vector2f& position, const sf::Vector2u& gridPosition, const int healthPoints);
	std::shared_ptr<GameObject> CreateBall(const sf::Vector2f& position, const sf::Vector2f& direction, const float radius, const float speed = 100.f);
	std::shared_ptr<GameObject> CreatePaddle(const sf::Vector2f& position, const float speed);

	void Start();
	void OnBrickDestroyed(const sf::Vector2u& gridPosition);

protected:

	int CountEmptySlots();
	void AddBrickAtRandomLocation();
	void AddBoundsOfMap();
};

