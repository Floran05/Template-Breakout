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

Collision CircleShapeComponent::CheckCollision(ShapeComponent& other)
{
    return other.CheckCollision(*this);
}

Collision CircleShapeComponent::CheckCollision(CircleShapeComponent& other)
{
    Collision collision = {};

    if (const CircleShapeComponent* circle = dynamic_cast<CircleShapeComponent*>(&other))
    {
        sf::Vector2f delta = this->m_Shape->getPosition() - circle->m_Shape->getPosition();
        float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);
        float radiusSum = this->GetRadius() + circle->GetRadius();

        if (distance < radiusSum)
        {
            collision.Target = &other;
            collision.Normale = delta / distance;
            collision.Position = this->m_Shape->getPosition();

            return collision;
        }
    }

    return collision;
}

Collision CircleShapeComponent::CheckCollision(RectShapeComponent& other)
{
    return other.CheckCollision(*this);
}