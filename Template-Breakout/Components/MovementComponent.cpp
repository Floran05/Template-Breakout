#include "MovementComponent.h"
#include "TransformComponent.h"
#include "../Services/TimeManager.h"
#include "../Objects/GameObject.h"

MovementComponent::MovementComponent()
	: mDirection(0.f, 0.f)
	, mSpeed(0.f)
{
}

MovementComponent::MovementComponent(const sf::Vector2f& initialDirection)
	: mDirection(initialDirection)
	, mSpeed(100.f)
{
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::Start()
{
}

void MovementComponent::Update()
{
	if (!m_Owner) return;
	const float deltaTime = static_cast<float>(I(TimeManager)->GetDeltaTime());
	m_Owner->Transform->Position += sf::Vector2f(mDirection.x * deltaTime * mSpeed, mDirection.y * deltaTime * mSpeed);
}
