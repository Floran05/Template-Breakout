#include "RectShapeComponent.h"

RectShapeComponent::RectShapeComponent(const char* fileName)
{
	m_filePath = fileName;
	m_Shape = std::make_shared<sf::RectangleShape>();
}

void RectShapeComponent::Update()
{
}

Collision RectShapeComponent::CheckCollision(ShapeComponent& other)
{
	return other.CheckCollision(*this);
}

Collision RectShapeComponent::CheckCollision(CircleShapeComponent& other)
{
	return other.CheckCollision(*this);
}

Collision RectShapeComponent::CheckCollision(RectShapeComponent& other)
{
    Collision collision = {};

    if (const RectShapeComponent* rect = dynamic_cast<RectShapeComponent*>(&other))
    {
        sf::FloatRect thisBounds = this->m_Shape->getGlobalBounds();
        sf::FloatRect otherBounds = rect->m_Shape->getGlobalBounds();

        std::optional<sf::FloatRect> intersection = thisBounds.findIntersection(otherBounds);

        if (intersection)
        {
            collision.Target = &other;
            collision.Position = intersection->position;
            collision.Normale = sf::Vector2f(1.f, 0.f);

            return collision;
        }
    }

    return collision;
}
