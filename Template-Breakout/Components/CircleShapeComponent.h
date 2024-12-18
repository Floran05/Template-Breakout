#pragma once
#include "ShapeComponent.h"
#include "RectShapeComponent.h"

class RectShapeComponent;

class CircleShapeComponent :
    public ShapeComponent
{
public:
    CircleShapeComponent(const char* fileName, float radius);
    void Update();
    
    void SetRadius(float radius);
    float GetRadius() const;

    std::optional<Collision> CheckCollision(ShapeComponent& other) override;
    std::optional<Collision> CheckCollision(CircleShapeComponent& other);
    std::optional<Collision> CheckCollision(RectShapeComponent& other);
protected:
};

