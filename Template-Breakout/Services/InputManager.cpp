#include "InputManager.h"

#include "Windows.h"

EKeyState InputManager::GetKeyState(int key)
{
	if (key > mKeyStates.size() - 1) 
		return EKeyState::Up;

	return mKeyStates[key];
}

void InputManager::Update()
{
	size_t j = mKeyStates.size();
	for (int i = 0; i < j; i++)
	{
		if (GetAsyncKeyState(i) < 0)
		{
			if (mKeyStates[i] == EKeyState::Pressed)
			{
				mKeyStates[i] = EKeyState::Down;
			}
			else if (mKeyStates[i] != EKeyState::Down)
			{
				mKeyStates[i] = EKeyState::Pressed;
			}
		}
		else {
			if (mKeyStates[i] == EKeyState::Released)
			{
				mKeyStates[i] = EKeyState::Up;
			}
			else if (mKeyStates[i] != EKeyState::Up)
			{
				mKeyStates[i] = EKeyState::Released;
			}
		}
	}
}

bool InputManager::IsKeyDown(int key)
{
	return GetKeyState(key) <= EKeyState::Down;
}

bool InputManager::IsKeyPressed(int key)
{
	return GetKeyState(key) == EKeyState::Pressed;
}

bool InputManager::IsKeyReleased(int key)
{
	return GetKeyState(key) == EKeyState::Released;
}

bool InputManager::IsKeyUp(int key)
{
	return GetKeyState(key) >= EKeyState::Up;
}
