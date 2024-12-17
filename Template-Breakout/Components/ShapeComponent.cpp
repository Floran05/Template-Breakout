#include "ShapeComponent.h"
#include "../Services/ResourceManager.h"
#include "../Services/GameManager.h"
#include "../Objects/GameObject.h"
#include "../Components/TransformComponent.h"
#include "../resources.h"

ShapeComponent::ShapeComponent(const char* filePath)
	: m_filePath(filePath)
	, m_Texture(nullptr)
	, m_Shape(nullptr)
{
}

void ShapeComponent::OnCreated()
{	
	m_Texture = I(ResourceManager)->GetTexture(m_filePath);
}

void ShapeComponent::Update()
{
}

void ShapeComponent::Draw()
{
	if (!m_Owner) return;
	m_Shape->setPosition(m_Owner->Transform->Position);
	m_Shape->setRotation(m_Owner->Transform->Rotation);
	m_Shape->setScale(m_Owner->Transform->Scale);
	I(GameManager)->GetWindow()->draw(*m_Shape);
}
