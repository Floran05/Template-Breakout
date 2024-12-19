#pragma once

class GameObject;

#define IS_BASE_OF_ASSERT(Base, T)   \
    static_assert(std::is_base_of<Base, T>::value, #T " must be derived of class: " #Base)

class Component
{
public:
	Component();
	virtual ~Component();

	void SetOwner(GameObject* gameObject) { m_Owner = gameObject; }
	GameObject* GetOwner() const { return m_Owner; }

	virtual void OnCreated() {};
	virtual void Start() {};
	virtual void Update() {};
	virtual void Draw() {};
	virtual void LateUpdate() {};
	virtual void OnRemoved() {};

protected:
	GameObject* m_Owner = nullptr;
};
