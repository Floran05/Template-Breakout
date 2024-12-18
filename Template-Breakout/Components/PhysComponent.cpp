#include "PhysComponent.h"

PhysComponent::PhysComponent(EBodyType bodyType, const GameObjectList& gameObjectList)
	: m_GameObjectList(gameObjectList)
    , m_pShapeComponent(nullptr)
    , m_lastCollision(nullptr)
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

        if (m_lastCollision && m_lastCollision->Target == otherShapeComponent)
        {
            m_lastCollision = nullptr;
            continue;
        }

        if (auto collision = m_pShapeComponent->CheckCollision(*otherShapeComponent))
        {
            m_lastCollision = &collision.value();
            RaiseCollision(*collision);
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