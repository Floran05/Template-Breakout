#include "PaddleControlComponent.h"
#include "../Services/InputManager.h"
#include "../Services/GameManager.h"
#include "TransformComponent.h"
#include "MovementComponent.h"
#include "ShapeComponent.h"

#include "Windows.h"
#include "../resources.h"

void PaddleControlComponent::Update()
{
	if (!m_Owner) return;
	MovementComponent* movement = m_Owner->GetComponent<MovementComponent>();
	ShapeComponent* shape = m_Owner->GetComponent<ShapeComponent>();
	if (!movement || !shape) return;

	sf::FloatRect bounds = shape->GetShape()->getLocalBounds();

	if (m_Owner->Transform->Position.x <= 0.f)
	{
		m_Owner->Transform->Position.x = 10.f;
		movement->SetDirection({ 0.f, 0.f });
		return;
	}

	if (m_Owner->Transform->Position.x + bounds.size.x >= WIN_WIDTH)
	{
		m_Owner->Transform->Position.x = WIN_WIDTH - bounds.size.x - 10.f;
		movement->SetDirection({ 0.f, 0.f });
		return;
	}


	if (I(InputManager)->IsKeyDown(VK_LEFT))
	{
		movement->SetDirection({ -1.0f, 0.f });
	}
	else if (I(InputManager)->IsKeyDown(VK_RIGHT))
	{
		movement->SetDirection({ 1.0f, 0.f });
	}
	else
	{
		movement->SetDirection({ 0.f, 0.f });
	}
}
