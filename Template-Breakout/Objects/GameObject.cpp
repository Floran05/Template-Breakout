#include "GameObject.h"
#include "../Components/TransformComponent.h"

GameObject::GameObject()
	: Transform(nullptr)
{
}

void GameObject::Update()
{
    for (auto& [type, component] : components) {
        component->Update();
    }
}