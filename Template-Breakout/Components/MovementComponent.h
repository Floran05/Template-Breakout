#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>

class MovementComponent : public Component
{
public:
	MovementComponent();
	MovementComponent(const sf::Vector2f& initialDirection);
	virtual ~MovementComponent();

	virtual void Start() override;
	virtual void Update() override;

protected:

	sf::Vector2f mDirection;
	float mSpeed;

};

