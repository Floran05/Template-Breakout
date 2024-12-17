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

    bool CheckCollision(const ShapeComponent& other) const override;
    bool CheckCollision(const CircleShapeComponent& other) const;
    bool CheckCollision(const RectShapeComponent& other) const;
protected:
};

