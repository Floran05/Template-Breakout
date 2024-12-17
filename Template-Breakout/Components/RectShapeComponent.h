#pragma once
#include "ShapeComponent.h"
#include "CircleShapeComponent.h"

class CircleShapeComponent;

class RectShapeComponent :
    public ShapeComponent
{
public:
    RectShapeComponent(const char* fileName);

    void Update();

    Collision CheckCollision(ShapeComponent& other) override;
    Collision CheckCollision(CircleShapeComponent& other);
    Collision CheckCollision(RectShapeComponent& other);
protected:
};