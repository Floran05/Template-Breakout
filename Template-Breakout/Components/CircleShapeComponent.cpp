#include "CircleShapeComponent.h"

static float radius = 0.f;

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
