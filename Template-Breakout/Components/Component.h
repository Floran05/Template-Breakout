#pragma once
#include "../Objects/GameObject.h"
class Component
{
public:
	Component(GameObject* gameObject) : m_Owner(gameObject) {};

	virtual void OnCreated() {};
	virtual void Start() {};
	virtual void Update() {};
	virtual void Draw() {};
	virtual void LateUpdate() {};
	virtual void OnRemoved() {};

private:
	GameObject* m_Owner;
};

