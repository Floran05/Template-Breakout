#include "SpawnerManager.h"
#include "../Objects/Brick.h"
#include "../Components/CircleShapeComponent.h"
#include "../Components/RectShapeComponent.h"
#include "../Components/MovementComponent.h"
#include "../Components/RotatingComponent.h"
#include "../Components/PaddleControlComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/BounceComponent.h"
#include "../Services/GameManager.h"

#include <random>
#include <functional>
#include "../Components/PhysComponent.h"

SpawnerManager::SpawnerManager()
	: mIsInGrowPhase(true)
{
	const sf::Vector2u windowSize = I(GameManager)->GetWindowSize();
	const float width = (windowSize.x - (BRICK_COLUMNS_COUNT + 1) * BRICK_MARGIN) / BRICK_COLUMNS_COUNT;
	mBrickSize = sf::Vector2f(width, width * (1 / static_cast<float>(BRICK_RATIO)));

	for (auto& row : mGrid)
	{
		row.fill(false);
	}
}

SpawnerManager::~SpawnerManager()
{
}

std::shared_ptr<GameObject> SpawnerManager::CreateBrick(const sf::Vector2f& position, const sf::Vector2u& gridPosition, const int healthPoints)
{
	std::shared_ptr<Brick> brick = std::make_shared<Brick>(gridPosition, healthPoints);
	brick->Transform->Position = position;
	brick->AddComponent<RectShapeComponent>(BRICK_SPRITE_PATH, mBrickSize);
	return brick;
}

std::shared_ptr<GameObject> SpawnerManager::CreateBall(const sf::Vector2f& position, const sf::Vector2f& direction, const float radius, const float speed)
{
	std::shared_ptr<GameObject> ball = std::make_shared<GameObject>();
	ball->Transform->Position = position;
	ball->AddComponent<CircleShapeComponent>(BALL_SPRITE_PATH, radius);
	ball->AddComponent<MovementComponent>(direction);
	ball->AddComponent<RotatingComponent>(3.f);
	ball->AddComponent<BounceComponent>(direction);
	ball->AddComponent<PhysComponent>(PhysComponent::EBodyBall, I(GameManager)->GetObjectList());
	ball->GetComponent<PhysComponent>()->OnCollision(std::bind(&BounceComponent::HandleCollision, ball->GetComponent<BounceComponent>(), std::placeholders::_1));
	return ball;
}

std::shared_ptr<GameObject> SpawnerManager::CreatePaddle(const sf::Vector2f& position, const float speed)
{
	std::shared_ptr<GameObject> paddle = std::make_shared<GameObject>();
	paddle->Transform->Position = position;
	const int paddleWidth = I(GameManager)->GetWindowSize().x * PADDLE_RELATIVE_WIDTH;
	const float paddleHeight = paddleWidth * (1 / static_cast<float>(PADDLE_RATIO));
	paddle->AddComponent<RectShapeComponent>(PADDLE_SPRITE_PATH, sf::Vector2f(paddleWidth, paddleHeight));
	paddle->AddComponent<MovementComponent>(sf::Vector2f(0.f, 0.f), speed);
	paddle->AddComponent<PaddleControlComponent>();
	return paddle;
}

void SpawnerManager::Start()
{
	for (int i = 0; i < SPAWNER_START_BRICK_AMOUNT; ++i)
	{
		AddBrickAtRandomLocation();
	}
}

void SpawnerManager::OnBrickDestroyed(const sf::Vector2u& gridPosition)
{
	mGrid[gridPosition.x][gridPosition.y] = false;

	for (int i = 0; i < mIsInGrowPhase ? SPAWNER_GROW_PHASE_SPAWN_AMOUNT : 1; ++i)
	{
		AddBrickAtRandomLocation();
	}
}

int SpawnerManager::CountEmptySlots()
{
	int count = 0;
	for (auto row = mGrid.begin(); row != mGrid.end(); ++row)
	{
		for (auto col = (*row).begin(); col != (*row).end(); ++col)
		{
			if (!(*col)) ++count;
		}
	}
	return count;
}

void SpawnerManager::AddBrickAtRandomLocation()
{
	int emptySlots = CountEmptySlots();
	if (emptySlots < 1) return;

	std::random_device dev;
	std::mt19937 gen(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, emptySlots);

	const int randomTargetPosition = dist(gen);
	int countEmptySlots = 0;
	for (int r = 0, rm = mGrid.size(); r < rm; ++r)
	{
		for (int c = 0, cm = mGrid[r].size(); c < cm; ++c)
		{
			if (!mGrid[r][c])
			{
				++countEmptySlots;
				if (countEmptySlots == randomTargetPosition)
				{
					std::shared_ptr<GameObject> brick = CreateBrick(
						{ c * (mBrickSize.x + BRICK_MARGIN) + BRICK_MARGIN, r * (mBrickSize.y + BRICK_MARGIN) + BRICK_MARGIN },
						sf::Vector2u(r, c),
						1
					);
					I(GameManager)->AddGameObject(brick);
					return;
				}
			}
		}
	}
}