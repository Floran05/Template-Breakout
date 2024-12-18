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

    Collision CheckCollision(ShapeComponent& other) override;
    Collision CheckCollision(CircleShapeComponent& other);
    Collision CheckCollision(RectShapeComponent& other);

    void SetSize(const sf::Vector2f& size);
    const sf::Vector2f& GetSize() const;
protected:
};