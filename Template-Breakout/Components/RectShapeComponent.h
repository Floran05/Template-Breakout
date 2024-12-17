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

    bool CheckCollision(const ShapeComponent& other) const override;
    bool CheckCollision(const CircleShapeComponent& other) const;
    bool CheckCollision(const RectShapeComponent& other) const;
protected:
};