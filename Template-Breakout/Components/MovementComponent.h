#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>

class MovementComponent : public Component
{
public:
	MovementComponent();
	MovementComponent(const sf::Vector2f& initialDirection, const float initialSpeed = 100.f);
	~MovementComponent();

	void Start() override;
	void Update() override;

	void SetDirection(const sf::Vector2f& newDirection) { mDirection = newDirection; }

protected:

	sf::Vector2f mDirection;
	float mSpeed;

};

