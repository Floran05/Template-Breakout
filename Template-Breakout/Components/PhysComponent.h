#pragma once
#include "Component.h"

#include "../Objects/GameObject.h"
#include "../Components/ShapeComponent.h"

#include <functional>

class PhysComponent :
    public Component
{
public:
	using CollisionCallback = std::function<void(const Collision&)>;

	enum EBodyType
	{
		EBodyPaddle = (1 << 0),
		EBodyBall = (1 << 1),
		EBodyBrick = (1 << 2),
	};

	explicit PhysComponent(EBodyType bodyType, const GameObjectList& gameObjectList);
	~PhysComponent();

	void Update();

	void OnCollision(const CollisionCallback& callback);
	void RaiseCollision(const Collision& collision);

	void ResetLastCollisionTarget() { m_lastCollisionTarget = nullptr; }

protected:
	const GameObjectList& m_GameObjectList;
	CollisionCallback m_collisionCallback;
	ShapeComponent* m_pShapeComponent;
	GameObject* m_lastCollisionTarget;
	EBodyType m_eBodyType;
};

