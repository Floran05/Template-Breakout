#include "Component.h"

Component::Component()
	: m_Owner(nullptr)
{
}

Component::Component(GameObject* gameObject)
	: m_Owner(gameObject)
{
}

Component::~Component()
{
	delete m_Owner;
}
