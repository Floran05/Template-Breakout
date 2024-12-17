#include "SpriteComponent.h"
#include "../Services/ResourceManager.h"
#include "../Services/GameManager.h"
#include "../resources.h"

void SpriteComponent::OnCreated()
{
	//m_Texture.loadFromFile();
	
	m_Sprite = I(ResourceManager)->GetSprite(m_filePath);
}

void SpriteComponent::Update()
{
	//I(GameManager)->GetWindow()->draw(*(m_Sprite.get()));
}
