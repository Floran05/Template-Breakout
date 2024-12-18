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
    sf::Vector2f centerA = m_Shape->getPosition();
    sf::Vector2f centerB = other.m_Shape->getPosition();
    float radiusA = GetRadius();
    float radiusB = other.GetRadius();

    sf::Vector2f delta = centerB - centerA;
    float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);

    if (distance < radiusA + radiusB) {
        Collision collision;
        collision.Target = &other;
        collision.Normale = delta / distance;  // Normalisation
        collision.Position = centerA + collision.Normale * radiusA;
        return collision;
    }

    return std::nullopt;
}

std::optional<Collision> CircleShapeComponent::CheckCollision(RectShapeComponent& other)
{
    const sf::FloatRect& rectBounds = other.GetShape()->getGlobalBounds();
    sf::Vector2f circleCenter = m_Shape->getPosition();
    float circleRadius = GetRadius();

    if (rectBounds.position.length() == 0 || circleCenter.length() == 0)
        return std::nullopt;

    float closestX = std::clamp(circleCenter.x, rectBounds.position.x, rectBounds.position.x + rectBounds.size.x);
    float closestY = std::clamp(circleCenter.y, rectBounds.position.y, rectBounds.position.y + rectBounds.size.y);

    sf::Vector2f closestPoint(closestX, closestY);
    sf::Vector2f delta = circleCenter - closestPoint;
    float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);

    if (distance < circleRadius) {
        Collision collision;
        collision.Target = &other;
        collision.Normale = delta / distance;  // Normalisation
        collision.Position = closestPoint;
        return collision;
    }
    return std::nullopt;
}