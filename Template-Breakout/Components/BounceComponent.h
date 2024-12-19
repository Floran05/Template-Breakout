#pragma once

#include "Component.h"

#include <SFML/System/Vector2.hpp>
#include "ShapeComponent.h"


#include <SFML/Audio.hpp>
#include "../resources.h"

class BounceComponent : public Component
{
public:
	BounceComponent();
	BounceComponent(const sf::Vector2f& initialDirection, const float initialSpeed = 100.f);
	virtual ~BounceComponent();

	virtual void Start() override;
	virtual void Update() override;

	void HandleCollision(const Collision& collision);

	void SetPosition(const sf::Vector2f& position);
	const sf::Vector2f& GetPosition() const;

	void SetDirection(const sf::Vector2f& direction);
	const sf::Vector2f& GetDirection() const;

private:
	sf::Vector2f m_position;
	sf::Vector2f m_direction;

	sf::Vector2f Normalize(const sf::Vector2f& vector) const;

	sf::Vector2f Reflect(const sf::Vector2f& vector, const sf::Vector2f& normal) const;

	const sf::SoundBuffer buffer = sf::SoundBuffer(BOUNCE_AUDIO);
	sf::Sound m_sound = sf::Sound(buffer);
	
	float m_speed;
};
