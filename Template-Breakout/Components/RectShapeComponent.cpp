#include "RectShapeComponent.h"

RectShapeComponent::RectShapeComponent(const char* fileName, const sf::Vector2f& size)
{
	m_filePath = fileName;
	m_Shape = std::make_shared<sf::RectangleShape>();
	SetSize(size);
}

void RectShapeComponent::Update()
{
}

std::optional<Collision> RectShapeComponent::CheckCollision(ShapeComponent& other)
{
    if (auto* otherCircle = dynamic_cast<CircleShapeComponent*>(&other))
    {
        return CheckCollision(*otherCircle);
    }
    else if (auto* otherRect = dynamic_cast<RectShapeComponent*>(&other))
    {
        return CheckCollision(*otherRect);
    }

    return std::nullopt;
}

std::optional<Collision> RectShapeComponent::CheckCollision(CircleShapeComponent& other)
{
	return other.CheckCollision(*this);
}

std::optional<Collision> RectShapeComponent::CheckCollision(RectShapeComponent& other)
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

void RectShapeComponent::SetSize(const sf::Vector2f& size)
{
	if (std::shared_ptr<sf::RectangleShape> rect = std::dynamic_pointer_cast<sf::RectangleShape>(m_Shape))
	{
		rect->setSize(size);
	}
}

const sf::Vector2f& RectShapeComponent::GetSize() const
{
    std::shared_ptr<sf::RectangleShape> rect = std::dynamic_pointer_cast<sf::RectangleShape>(m_Shape);
    return rect ? rect->getSize() : sf::Vector2f(0.f, 0.f);
}
