#pragma once
#include "Singleton.h"

#include "GameManager.h"

#include <SFML/Graphics.hpp>
#include "../Components/ShapeComponent.h"

struct DebugElement {
    std::unique_ptr<sf::Drawable> drawable;
    std::chrono::steady_clock::time_point timestamp;
    std::chrono::milliseconds duration;

    DebugElement(std::unique_ptr<sf::Drawable> draw, std::chrono::milliseconds dur)
        : drawable(std::move(draw))
        , timestamp(std::chrono::steady_clock::now())
        , duration(dur) {}
};

class DebugManager :
    public Singleton<DebugManager>
{
    friend class Singleton<DebugManager>;

public:
    void Update();

    // duration in seconds
    void AddDebugCollision(const Collision& collision, std::chrono::milliseconds duration = std::chrono::milliseconds(5000));

private:
    std::vector<DebugElement> m_Elements;
};

