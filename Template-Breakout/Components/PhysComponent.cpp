#include "PhysComponent.h"

#include "../Services/DebugManager.h"

PhysComponent::PhysComponent(EBodyType bodyType, const GameObjectList& gameObjectList)
	: m_GameObjectList(gameObjectList)
    , m_pShapeComponent(nullptr)
    , m_lastCollisionTarget(nullptr)
	, m_eBodyType(bodyType)
{
}

PhysComponent::~PhysComponent()
{
}

void PhysComponent::OnCollision(const CollisionCallback& callback)
{
    m_collisionCallback = callback;
}

void PhysComponent::Update()
{
    if (!m_pShapeComponent)
    {
        m_pShapeComponent = m_Owner->GetComponent<ShapeComponent>();
        if (!m_pShapeComponent)
        {
            assert(m_pShapeComponent);
            return;
        }
    }

    for (const auto& gameObject : m_GameObjectList)
    {
        if (gameObject.get() == m_Owner)
            continue;

        auto otherShapeComponent = gameObject->GetComponent<ShapeComponent>();
        if (!otherShapeComponent)
            continue;

        if (auto collision = m_pShapeComponent->CheckCollision(*otherShapeComponent))
        {
            if (m_lastCollisionTarget && m_lastCollisionTarget == collision->Target->GetOwner())
            {
                continue;
            }
            m_lastCollisionTarget = collision->Target->GetOwner();
            RaiseCollision(*collision);

            I(DebugManager)->AddDebugCollision(*collision, std::chrono::milliseconds(1000));
        }
    }
}

void PhysComponent::RaiseCollision(const Collision& collision)
{
    if (m_collisionCallback)
    {
        m_collisionCallback(collision);
    }
}