#pragma once

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "../Components/ShapeComponent.h"

#include "SFML/Audio.hpp"
#include "../resources.h"

class Brick : public GameObject
{
public:

	Brick();
	Brick(const sf::Vector2u& gridPosition, int healthPoint);
	virtual ~Brick();

private:

	sf::Vector2u mGridPosition;

	const sf::SoundBuffer buffer = sf::SoundBuffer(DESTROY_AUDIO);
	sf::Sound mSound = sf::Sound(buffer);

	int mHealthPoints;
public:

	sf::Vector2u GetGridPosition() const { return mGridPosition; }
	int GetHealthPoints() const { return mHealthPoints; }

	void OnHit(const Collision& collision);
	static const char* GetTexturePathByHealthPoints(int healthPoints);

};

