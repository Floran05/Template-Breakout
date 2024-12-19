#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include "../Services/GameManager.h"

class LoseComponent :
    public Component
{
public:
	LoseComponent() {};
	virtual ~LoseComponent() {};

	virtual void Update() override;

private:
	const sf::SoundBuffer buffer = sf::SoundBuffer(LOOSE_AUDIO);
	sf::Sound m_GameOverSound = sf::Sound(buffer);
};

