#pragma once

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "../Components/ShapeComponent.h"

class Brick : public GameObject
{
public:

	Brick();
	Brick(const sf::Vector2u& gridPosition, int healthPoint);
	virtual ~Brick();

private:

	sf::Vector2u mGridPosition;
	int mHealthPoints;

public:

	sf::Vector2u GetGridPosition() const { return mGridPosition; }
	int GetHealthPoints() const { return mHealthPoints; }
	bool IsPendingKill() const { return mHealthPoints < 1; }

	void OnHit(const Collision& collision);

};

