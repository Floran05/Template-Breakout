#include "Paddle.h"

#include "Windows.h"

#include "../Services/InputManager.h"
#include "../Services/TimeManager.h"


Paddle::Paddle() 
{
	sprite = new SpriteComponent(PADDLE_SPRITE_PATH);
}

void Paddle::Update() 
{
	HandleInput();
}

void Paddle::HandleInput()
{
	float moveDistance = speed * I(TimeManager)->GetDeltaTime();

	if (I(InputManager)->IsKeyPressed(VK_LEFT))
	{
	}
	if (I(InputManager)->IsKeyPressed(VK_RIGHT))
	{
	}
	// 
	// 	sf::Vector2f position = sprite.getPosition();
	// 	if (position.x < 0) {
	// 		sprite.setPosition(0, position.y);
	// 	}
	// 	if (position.x + sprite.getSize().x > windowWidth) {
	// 		sprite.setPosition(windowWidth - sprite.getSize().x, position.y);
	// 	}

}

void Paddle::Draw() 
{
	sprite->Update();
}

sf::Vector2f Paddle::GetPosition() const 
{
	return { 0, 0 } ;//sprite.GetPosition();
}

void Paddle::SetPosition(float x, float y) 
{
	//sprite.SetPosition(x, y);
}
