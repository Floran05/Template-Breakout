#pragma once
#include "ShapeComponent.h"
class CircleShapeComponent :
    public ShapeComponent
{
public:
    CircleShapeComponent(const char* fileName, float radius);
    void Update();
    
    void SetRadius(float radius);
    float GetRadius() const;
protected:
};

