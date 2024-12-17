#pragma once

#include "Component.h"

#include <SFML/Graphics.hpp>

class TransformComponent : public Component
{
public:

	TransformComponent();
	TransformComponent(const sf::Vector2f& position, const sf::Angle& rotation, const sf::Vector2f& scale);

	sf::Vector2f Position;
	sf::Angle Rotation;
	sf::Vector2f Scale;

};

