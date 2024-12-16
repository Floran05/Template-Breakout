#include "SpriteComponent.h"
#include "../resources.h"

void SpriteComponent::OnCreated()
{
	//m_Texture.loadFromFile();
	m_Sprite.setTexture(m_Texture);
}

void SpriteComponent::Update()
{
}
