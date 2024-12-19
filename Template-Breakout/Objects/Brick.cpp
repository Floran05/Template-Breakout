#include "Brick.h"
#include "../Services/SpawnerManager.h"
#include "../Components/PhysComponent.h"

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

void Brick::OnHit(const Collision& collision)
{
	--mHealthPoints;
	GetComponent<PhysComponent>()->ResetLastCollisionTarget();
	if (GetHealthPoints() < 1)
	{
		SetIsPendingKill(true);
		I(SpawnerManager)->OnBrickDestroyed(mGridPosition);

	}
}
