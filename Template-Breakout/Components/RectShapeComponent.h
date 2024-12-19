#pragma once
#include "CircleShapeComponent.h"
#include <SFML/Graphics.hpp>

class CircleShapeComponent;

class RectShapeComponent :
    public ShapeComponent
{
public:
    RectShapeComponent(const char* fileName, const sf::Vector2f& size);
    void Update();

    std::optional<Collision> CheckCollision(ShapeComponent& other) override;
    std::optional<Collision> CheckCollision(CircleShapeComponent& other);
    std::optional<Collision> CheckCollision(RectShapeComponent& other);

    void SetSize(const sf::Vector2f& size);
    const sf::Vector2f GetSize() const;
protected:
};