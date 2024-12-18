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

    template <class T, typename... Args>
    void AddComponent(Args&&... args);

    template <class T>
    void RemoveComponent();

    template <class T>
    T* GetComponent();

    virtual void Update();
    virtual void Draw();
  
    TransformComponent* Transform;

protected:
    std::unordered_map<std::type_index, std::unique_ptr<Component>> components;


};

template<class T, typename ...Args>
inline void GameObject::AddComponent(Args && ...args)
{
    IS_BASE_OF_ASSERT(Component, T);
    auto type = std::type_index(typeid(T));
    components[type] = std::make_unique<T>(std::forward<Args>(args)...);
    components[type]->SetOwner(this);
    components[type]->OnCreated();
}

template<class T>
inline void GameObject::RemoveComponent()
{
    IS_BASE_OF_ASSERT(Component, T);
    auto type = std::type_index(typeid(T));
    components.erase(type);
}

template<class T>
inline T* GameObject::GetComponent()
{
    IS_BASE_OF_ASSERT(Component, T);
    /*auto type = std::type_index(typeid(T));
    auto it = components.find(type);
    if (it != components.end()) {
        return static_cast<T*>(it->second.get());
    }*/
    for (auto& [type, component] : components)
    {
        // Utilise dynamic_cast pour vérifier si le composant est du type ou d’un type dérivé
        if (auto* result = dynamic_cast<T*>(component.get()))
        {
            return result; // Retourne le composant trouvé
        }
    }
    return nullptr;
}

typedef std::list<std::unique_ptr<GameObject>> GameObjectList;