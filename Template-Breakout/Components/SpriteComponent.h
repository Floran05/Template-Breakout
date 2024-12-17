#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>
#include <filesystem>

class SpriteComponent : public Component
{
public:
    SpriteComponent(const char* filePath) : m_filePath(filePath) {};
    void OnCreated() override;
    void Update() override;
private:
    std::filesystem::path m_filePath;
    std::shared_ptr<sf::Sprite> m_Sprite;
};