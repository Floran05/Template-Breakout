#include "RectShapeComponent.h"

RectShapeComponent::RectShapeComponent(const char* fileName)
{
	m_filePath = fileName;
	m_Shape = std::make_shared<sf::RectangleShape>();
}

void RectShapeComponent::Update()
{
}

bool RectShapeComponent::CheckCollision(const ShapeComponent& other) const
{
	return other.CheckCollision(*this);
}

bool RectShapeComponent::CheckCollision(const CircleShapeComponent& other) const
{
	return other.CheckCollision(*this);
}

bool RectShapeComponent::CheckCollision(const RectShapeComponent& other) const
{
	return m_Shape->getGlobalBounds().findIntersection(other.m_Shape->getGlobalBounds()) != std::nullopt;
}
