#include "Brick.h"
#include "../Services/SpawnerManager.h"
#include "../Services/GameManager.h"
#include "../Components/PhysComponent.h"

Brick::Brick()
	: mGridPosition({0, 0})
	, mHealthPoints(1)
{
	const sf::SoundBuffer buffer = sf::SoundBuffer(DESTROY_AUDIO);
	mSound = std::make_unique<sf::Sound>(buffer);
}

Brick::Brick(const sf::Vector2u& gridPosition, int healthPoint)
	: mGridPosition(gridPosition)
	, mHealthPoints(healthPoint)
{
	const sf::SoundBuffer buffer = sf::SoundBuffer(DESTROY_AUDIO);
	mSound = std::make_unique<sf::Sound>(buffer);
}

Brick::~Brick()
{
}

void Brick::OnHit(const Collision& collision)
{
	--mHealthPoints;
	GetComponent<PhysComponent>()->ResetLastCollisionTarget();
	GetComponent<ShapeComponent>()->SetTexture(Brick::GetTexturePathByHealthPoints(mHealthPoints));
	if (GetHealthPoints() < 1)
	{
		SetIsPendingKill(true);
		I(SpawnerManager)->OnBrickDestroyed(mGridPosition);
		I(GameManager)->IncreaseScore();

		if (mSound->getStatus() != sf::SoundSource::Status::Playing)
		{
			mSound->setVolume(22);
			mSound->play();
		}
	}
}

const char* Brick::GetTexturePathByHealthPoints(int healthPoints)
{
	switch (healthPoints)
	{
	case 1:
		return BRICK3_SPRITE_PATH;
	case 2:
		return BRICK2_SPRITE_PATH;
	}
	return BRICK_SPRITE_PATH;
}