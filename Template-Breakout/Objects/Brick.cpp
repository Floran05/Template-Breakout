#include "Brick.h"
#include "../Services/SpawnerManager.h"

Brick::Brick()
	: mGridPosition({0, 0})
	, mHealthPoints(1)
{
}

Brick::Brick(const sf::Vector2u& gridPosition, int healthPoint)
	: mGridPosition(gridPosition)
	, mHealthPoints(healthPoint)
{
}

Brick::~Brick()
{
}

void Brick::OnHit()
{
	--mHealthPoints;
	if (IsPendingKill())
	{
		I(SpawnerManager)->OnBrickDestroyed(mGridPosition);
	}
}