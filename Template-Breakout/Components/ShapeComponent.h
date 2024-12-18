#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <concepts>

class ShapeComponent;

template<class T>
concept ShapeComponentConcept = std::is_base_of<ShapeComponent, T>::value;

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

    virtual std::optional<Collision> CheckCollision(ShapeComponent& other) = 0;
protected:
    std::filesystem::path m_filePath;
    std::shared_ptr<sf::Shape> m_Shape;

private:
    std::shared_ptr<sf::Texture> m_Texture;
};