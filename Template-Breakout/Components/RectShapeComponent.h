#pragma once
#include "ShapeComponent.h"
class RectShapeComponent :
    public ShapeComponent
{
public:
    RectShapeComponent(const char* fileName);
    void Update();

protected:
};

