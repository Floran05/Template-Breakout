#include "GameObject.h"
#include "../Components/TransformComponent.h"

GameObject::GameObject()
    : mIsPendingKill(false)
{
    AddComponent<TransformComponent>();
    Transform = GetComponent<TransformComponent>();
}

void GameObject::Update()
{
    for (auto& [type, component] : components) {
        component->Update();
    }
}

void GameObject::Draw()
{
    for (auto& [type, component] : components) {
        component->Draw();
    }
}
