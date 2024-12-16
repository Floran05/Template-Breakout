#pragma once

#include "Component.h"

#include <SFML/Graphics.hpp>

class TransformComponent : public Component
{
public:

	TransformComponent();
	TransformComponent(const sf::Vector2f& position, const sf::Vector2f& rotation, const sf::Vector2f& scale);

	sf::Vector2f Position;
	sf::Vector2f Rotation;
	sf::Vector2f Scale;

};

