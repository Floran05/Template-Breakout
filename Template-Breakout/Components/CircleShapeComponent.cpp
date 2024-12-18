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
    if (std::shared_ptr<sf::CircleShape> circle = std::dynamic_pointer_cast<sf::CircleShape>(m_Shape)) 
    {
        circle->setRadius(radius);
    }
}

float CircleShapeComponent::GetRadius() const {
    auto circle = std::dynamic_pointer_cast<sf::CircleShape>(m_Shape);
    return circle ? circle->getRadius() : 0.0f;
}

std::optional<Collision> CircleShapeComponent::CheckCollision(ShapeComponent& other)
{
    return other.CheckCollision(*this);
}

std::optional<Collision> CircleShapeComponent::CheckCollision(CircleShapeComponent& other)
{
    Collision collision = {};

    if (const CircleShapeComponent* circle = dynamic_cast<CircleShapeComponent*>(&other))
    {
        sf::Vector2f delta = m_Shape->getPosition() - circle->m_Shape->getPosition();
        float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);
        float radiusSum = GetRadius() + circle->GetRadius();

        if (distance < radiusSum)
        {
            collision.Target = &other;
            collision.Normale = delta / distance;
            collision.Position = m_Shape->getPosition();

            return collision;
        }
    }

    return std::nullopt;
}

std::optional<Collision> CircleShapeComponent::CheckCollision(RectShapeComponent& other)
{
    return std::nullopt;
}