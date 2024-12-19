#include "ShapeComponent.h"
#include "../Services/ResourceManager.h"
#include "../Services/GameManager.h"
#include "../Objects/GameObject.h"
#include "../Components/TransformComponent.h"
#include "../resources.h"

ShapeComponent::ShapeComponent()
	: m_Texture(nullptr)
	, m_Shape(nullptr)
{
}

void ShapeComponent::OnCreated()
{	
	SetTexture(m_filePath);
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

void ShapeComponent::SetTexture(const std::filesystem::path& filepath)
{
	m_Texture = I(ResourceManager)->GetTexture(filepath);
	if (m_Shape && m_Texture)
		m_Shape->setTexture(m_Texture.get());
}
