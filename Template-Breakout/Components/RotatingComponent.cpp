#include "RotatingComponent.h"
#include "../Objects/GameObject.h"
#include "../Components/TransformComponent.h"

RotatingComponent::RotatingComponent()
	: mRotationSpeed(0.f)
{
}

RotatingComponent::RotatingComponent(const float rotationSpeed)
	: mRotationSpeed(rotationSpeed)
{
}

RotatingComponent::~RotatingComponent()
{
}

void RotatingComponent::Update()
{
	if (!m_Owner) return;

	m_Owner->Transform->Rotation += sf::degrees(mRotationSpeed);
}
