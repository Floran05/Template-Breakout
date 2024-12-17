#include "Component.h"
#include "../Objects/GameObject.h"

Component::Component()
	: m_Owner(nullptr)
{
	OnCreated();
}

Component::Component(GameObject* gameObject)
	: m_Owner(gameObject)
{
	OnCreated();
}

Component::~Component()
{
	delete m_Owner;
}
