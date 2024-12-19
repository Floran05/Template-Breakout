#include "LoseComponent.h"

void LoseComponent::Update()
{
	if (m_Owner && !I(GameManager)->IsGameState(EGameOverState))
	{
		if ((m_Owner->Transform->Position.y - BALL_RADIUS) > WIN_HEIGHT)
		{
			I(GameManager)->SetIsGameOver();
			if (m_GameOverSound.getStatus() != sf::SoundSource::Status::Playing)
				m_GameOverSound.play();
		}
	}
}
