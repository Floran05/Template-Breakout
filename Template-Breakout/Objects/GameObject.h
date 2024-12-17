#pragma once
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>
#include "../Components/Component.h"

class TransformComponent;

class GameObject
{
public:

	GameObject();

    template <typename T, typename... Args>
    void AddComponent(Args&&... args);

    template <typename T>
    void RemoveComponent();

    template <typename T>
    T* GetComponent();

    void Update();

    TransformComponent* Transform;

protected:
    std::unordered_map<std::type_index, std::unique_ptr<Component>> components;


};

template<typename T, typename ...Args>
inline void GameObject::AddComponent(Args && ...args)
{
    auto type = std::type_index(typeid(T));
    components[type] = std::make_unique<T>(std::forward<Args>(args)...);
    components[type]->SetOwner(this);
    components[type]->OnCreated();
}

template<typename T>
inline void GameObject::RemoveComponent()
{
    auto type = std::type_index(typeid(T));
    components.erase(type);
}

template<typename T>
inline T* GameObject::GetComponent()
{
    auto type = std::type_index(typeid(T));
    auto it = components.find(type);
    if (it != components.end()) {
        return static_cast<T*>(it->second.get());
    }
    return nullptr;
}
