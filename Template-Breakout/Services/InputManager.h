#pragma once

#include "Singleton.h"

#include <array>

enum class EKeyState : unsigned char
{
	Pressed,
	Down,
	Released,
	Up
};

class InputManager : public Singleton<InputManager>
{
	friend class Singleton<InputManager>;

private:

	std::array<EKeyState, 256> mKeyStates;

protected:

	EKeyState GetKeyState(int key);

public:

	void Update();

	bool IsKeyDown(int key);
	bool IsKeyPressed(int key);
	bool IsKeyReleased(int key);
	bool IsKeyUp(int key);

};

