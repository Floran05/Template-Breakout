#pragma once
class Component
{
public:
	Component() {};

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Stop() = 0;
};

