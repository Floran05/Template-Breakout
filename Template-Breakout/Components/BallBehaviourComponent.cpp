#include "BallBehaviourComponent.h"

BallBehaviourComponent::BallBehaviourComponent()
	: m_currentLevel(0)
{
}

void BallBehaviourComponent::Update()
{
	int score = I(GameManager)->GetGameScore();
	if (ShapeComponent* shape = m_Owner->GetComponent<ShapeComponent>())
	{
		if (score >= ANGRY_LEVEL2 && m_currentLevel != 2)
		{
			shape->SetTexture(GetBallPathByLevel(2));
			m_currentLevel++;
		}
		else if (score >= ANGRY_LEVEL1 && m_currentLevel != 1)
		{
			shape->SetTexture(GetBallPathByLevel(1));
			m_currentLevel++;
		}
		else if (score == 0 && m_currentLevel !=0 )
		{
			shape->SetTexture(GetBallPathByLevel(0));
			m_currentLevel = 0;
		}
	}
}

const char* BallBehaviourComponent::GetBallPathByLevel(int idx)
{
	switch (idx)
	{
	case 1:
		return BALL2_SPRITE_PATH;
	case 2:
		return BALL3_SPRITE_PATH;
	}
	return BALL_SPRITE_PATH;
}
