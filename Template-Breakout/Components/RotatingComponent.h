#pragma once

#include "Component.h"

class RotatingComponent : public Component
{
public:
	RotatingComponent();
	RotatingComponent(const float rotationSpeed = 3.f);
	virtual ~RotatingComponent();

	virtual void Update() override;

	void SetRotationSpeed(const float rotationSpeed) { mRotationSpeed = rotationSpeed; }

protected:

	float mRotationSpeed;
};

