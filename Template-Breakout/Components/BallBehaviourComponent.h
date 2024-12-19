#pragma once
#include "Component.h"

#include "ShapeComponent.h"
#include "../resources.h"
#include "../Services/GameManager.h"

class BallBehaviourComponent :
    public Component
{
public:
	BallBehaviourComponent();
	virtual ~BallBehaviourComponent() {};

	virtual void Update() override;
	static const char* GetBallPathByLevel(int idx);

private:
	int m_currentLevel;
};

