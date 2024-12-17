#include "CircleShapeComponent.h"

CircleShapeComponent::CircleShapeComponent(const char* fileName, float radius)
{
	m_filePath = fileName;
	m_Shape = std::make_shared<sf::CircleShape>(radius);
	m_Shape->setOrigin(sf::Vector2f(radius, radius));
}

void CircleShapeComponent::Update()
{
}

void CircleShapeComponent::SetRadius(float radius) {
    auto circle = std::dynamic_pointer_cast<sf::CircleShape>(m_Shape);
    if (circle) {
        circle->setRadius(radius);
    }
}

float CircleShapeComponent::GetRadius() const {
    auto circle = std::dynamic_pointer_cast<sf::CircleShape>(m_Shape);
    return circle ? circle->getRadius() : 0.0f;
}

bool CircleShapeComponent::CheckCollision(const ShapeComponent& other) const
{
    return other.CheckCollision(*this);
}

bool CircleShapeComponent::CheckCollision(const CircleShapeComponent& other) const
{
    float dx = m_Shape->getPosition().x - other.m_Shape->getPosition().x;
    float dy = m_Shape->getPosition().y - other.m_Shape->getPosition().y;
    float distance = std::sqrt(dx * dx + dy * dy);
    return distance < (GetRadius() + other.GetRadius());
}

bool CircleShapeComponent::CheckCollision(const RectShapeComponent& other) const
{
    return other.CheckCollision(*this);
}