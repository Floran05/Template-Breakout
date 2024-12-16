#include "TransformComponent.h"

TransformComponent::TransformComponent()
	: Position(0.f, 0.f)
	, Rotation(0.f, 0.f)
	, Scale(0.f, 0.f)
{
}

TransformComponent::TransformComponent(const sf::Vector2f& position, const sf::Vector2f& rotation, const sf::Vector2f& scale)
	: Position(position)
	, Rotation(rotation)
	, Scale(scale)
{
}
