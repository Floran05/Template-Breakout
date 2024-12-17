#pragma once

#include "GameObject.h"

#include "../resources.h"

#include "../Components/ShapeComponent.h"

class Paddle : public GameObject
{
private:
	ShapeComponent *sprite;
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


