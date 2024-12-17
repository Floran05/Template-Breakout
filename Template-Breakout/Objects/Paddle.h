#pragma once

#include "GameObject.h"

#include "../resources.h"

#include "../Components/SpriteComponent.h"

class Paddle : public GameObject
{
private:
	SpriteComponent *sprite;
	float speed;
	float windowWidth;

public:
	Paddle();

	void Update() override;

	void Draw();

	void HandleInput();

	sf::Vector2f GetPosition() const;

	void SetPosition(float x, float y);

};


