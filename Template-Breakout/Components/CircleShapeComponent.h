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

    Collision CheckCollision(ShapeComponent& other) override;
    Collision CheckCollision(CircleShapeComponent& other);
    Collision CheckCollision(RectShapeComponent& other);
protected:
};

