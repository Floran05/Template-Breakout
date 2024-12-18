#include "BounceComponent.h"
#include <cmath>

#include "../Services/TimeManager.h"
#include "../Objects/GameObject.h"
#include "TransformComponent.h"
#include "MovementComponent.h"



BounceComponent::BounceComponent() : 
	m_speed(100.0f), 
	m_direction(0.0f, 0.0f), 
	m_position(0.0f, 0.0f)
{
}

BounceComponent::BounceComponent(const sf::Vector2f& initialDirection, const float initialSpeed) :
	m_speed(initialSpeed), 
	m_direction(initialDirection),
	m_position(0.0f, 0.0f)
{
}

BounceComponent::~BounceComponent()
{
}

void BounceComponent::Start()
{

}


void BounceComponent::Update()
{
	if (!m_Owner) 
		return;

	//float deltaTime = I(TimeManager)->GetDeltaTime();
	//m_position += m_direction * m_speed * deltaTime;

	//m_Owner->Transform->Position = m_position;

	m_Owner->GetComponent<MovementComponent>()->SetDirection(m_direction);
}

void BounceComponent::HandleCollision(const Collision& collision)
{	
	m_direction = Reflect(m_direction, collision.Normale);
	m_direction = Normalize(m_direction);
	m_position = collision.Position + collision.Normale * 0.1f;
}

void BounceComponent::SetPosition(const sf::Vector2f& position)
{
	m_position = position;
}

const sf::Vector2f& BounceComponent::GetPosition() const
{
	return m_position;
}

void BounceComponent::SetDirection(const sf::Vector2f& direction)
{
	m_direction = Normalize(direction);
}

const sf::Vector2f& BounceComponent::GetDirection() const
{
	return m_direction;
}

sf::Vector2f BounceComponent::Normalize(const sf::Vector2f& vector) const
{
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	if (length != 0)
		return sf::Vector2f(vector.x / length, vector.y / length);
	return sf::Vector2f(0.0f, 0.0f);
}

sf::Vector2f BounceComponent::Reflect(const sf::Vector2f& vector, const sf::Vector2f& normal) const
{
	return vector - 2.0f * (vector.x * normal.x + vector.y * normal.y) * normal;
}
