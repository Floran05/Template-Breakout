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
    sf::FloatRect thisBounds = m_Shape->getGlobalBounds();
    sf::FloatRect otherBounds = other.m_Shape->getGlobalBounds();

    if (thisBounds.findIntersection(otherBounds)) {
        Collision collision;
        collision.Target = &other;
        collision.Normale = sf::Vector2f(1.0f, 0.0f);  // Normale par défaut (à ajuster selon vos besoins)
        collision.Position = sf::Vector2f(thisBounds.position.x, thisBounds.position.y);  // Point arbitraire
        return collision;
    }
    return std::nullopt;
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
