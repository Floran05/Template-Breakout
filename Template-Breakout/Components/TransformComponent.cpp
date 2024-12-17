#include "TransformComponent.h"

TransformComponent::TransformComponent()
	: Position(0.f, 0.f)
	, Rotation(sf::radians(0.f))
	, Scale(0.3f, 0.3f)
{
}

TransformComponent::TransformComponent(const sf::Vector2f& position, const sf::Angle& rotation, const sf::Vector2f& scale)
	: Position(position)
	, Rotation(rotation)
	, Scale(scale)
{
}
