#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>
#include <filesystem>

class ShapeComponent : public Component
{
public:
    ShapeComponent(const char* filePath);
    void OnCreated() override;
    void Update() override;
    void Draw() override;
private:
    std::filesystem::path m_filePath;
    std::shared_ptr<sf::Texture> m_Texture;
    sf::Shape* m_Shape;
};