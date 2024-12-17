#include "PaddleControlComponent.h"
#include "../Services/InputManager.h"
#include "../Objects/GameObject.h"
#include "TransformComponent.h"
#include "MovementComponent.h"

#include "Windows.h"

void PaddleControlComponent::Update()
{
	if (!m_Owner) return;
	MovementComponent* movement = m_Owner->GetComponent<MovementComponent>();
	if (!movement) return;
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
