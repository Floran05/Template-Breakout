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

void RectShapeComponent::SetSize(const sf::Vector2f& size)
{
	if (std::shared_ptr<sf::RectangleShape> rect = std::dynamic_pointer_cast<sf::RectangleShape>(m_Shape))
	{
		rect->setSize(size);
	}
}
