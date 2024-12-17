#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>
#include <filesystem>

class ShapeComponent : public Component
{
public:
    ShapeComponent();
    void OnCreated() override;
    void Update() override;
    void Draw() override;
    
    virtual bool CheckCollision(const ShapeComponent& other) const = 0;
protected:
    std::filesystem::path m_filePath;
    std::shared_ptr<sf::Shape> m_Shape;

private:
    std::shared_ptr<sf::Texture> m_Texture;
};