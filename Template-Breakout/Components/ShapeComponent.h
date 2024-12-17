#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>
#include <filesystem>

class ShapeComponent;

struct Collision
{
    ShapeComponent* Target;
    sf::Vector2f Normale;
    sf::Vector2f Position;
};

class ShapeComponent : public Component
{
public:
    ShapeComponent();
    void OnCreated() override;
    void Update() override;
    void Draw() override;

    virtual Collision CheckCollision(ShapeComponent& other) = 0;
protected:
    std::filesystem::path m_filePath;
    std::shared_ptr<sf::Shape> m_Shape;

private:
    std::shared_ptr<sf::Texture> m_Texture;
};