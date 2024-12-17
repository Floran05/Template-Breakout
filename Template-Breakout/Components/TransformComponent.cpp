#include "TransformComponent.h"

TransformComponent::TransformComponent()
	: Position(0.f, 0.f)
	, Rotation(sf::radians(0.f))
	, Scale(1.f, 1.f)
{
}

TransformComponent::TransformComponent(const sf::Vector2f& position, const sf::Angle& rotation, const sf::Vector2f& scale)
	: Position(position)
	, Rotation(rotation)
	, Scale(scale)
{
}
