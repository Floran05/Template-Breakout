#pragma once
#include "ShapeComponent.h"
#include <SFML/Graphics.hpp>
class RectShapeComponent :
    public ShapeComponent
{
public:
    RectShapeComponent(const char* fileName, const sf::Vector2f& size);
    void Update();

    void SetSize(const sf::Vector2f& size);

protected:
};

