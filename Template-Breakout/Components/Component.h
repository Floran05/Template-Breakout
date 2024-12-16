#pragma once

#include "../Objects/GameObject.h"

class Component
{
public:
	Component();
	Component(GameObject* gameObject);
	virtual ~Component();

	void SetOwner(GameObject* gameObject) { m_Owner = gameObject; }

	virtual void OnCreated() {};
	virtual void Start() {};
	virtual void Update() {};
	virtual void Draw() {};
	virtual void LateUpdate() {};
	virtual void OnRemoved() {};

protected:
	GameObject* m_Owner;
};
