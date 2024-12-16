#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>

class SpriteComponent : public Component
{
public:
    void OnCreated() override;
    void Update() override;
private:
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;
};