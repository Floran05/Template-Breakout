#pragma once
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>
//#include <Compo>
class GameObject
{
public:
	GameObject();

    template <typename T, typename... Args>
    void addComponent(Args&&... args) {
        auto type = std::type_index(typeid(T));
        components[type] = std::make_unique<T>(std::forward<Args>(args)...);
    }

    template <typename T>
    void removeComponent() {
        auto type = std::type_index(typeid(T));
        components.erase(type);
    }

    template <typename T>
    T* getComponent() {
        auto type = std::type_index(typeid(T));
        auto it = components.find(type);
        if (it != components.end()) {
            return static_cast<T*>(it->second.get());
        }
        return nullptr;
    }

    void update() {
        for (auto& [type, component] : components) {
            component->update();
        }
    }

private:
    std::unordered_map<std::type_index, std::unique_ptr<Component>> components;
};

