#include "RectShapeComponent.h"

RectShapeComponent::RectShapeComponent(const char* fileName)
{
	m_filePath = fileName;
	m_Shape = std::make_shared<sf::RectangleShape>();
}

void RectShapeComponent::Update()
{
}