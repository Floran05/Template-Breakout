#include "DebugManager.h"

void DebugManager::Update()
{
    auto now = std::chrono::steady_clock::now();

    for (auto it = m_Elements.begin(); it != m_Elements.end();) 
    {
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - it->timestamp);

        if (elapsed >= it->duration) 
        {
            it = m_Elements.erase(it);
        }
        else 
        {
            I(GameManager)->GetWindow()->draw(*it->drawable);
            ++it;
        }
    }
}

void DebugManager::AddDebugCollision(const Collision& collision, std::chrono::milliseconds duration)
{
#ifdef _DEBUG
    auto line = std::make_unique<sf::VertexArray>(sf::PrimitiveType::Lines, 2);
    (*line)[0].position = collision.Position;
    (*line)[0].color = sf::Color::White;
    (*line)[1].position = collision.Position + collision.Normale * 20.f;
    (*line)[1].color = sf::Color::White;
    m_Elements.emplace_back(std::move(line), duration);

    auto overlay = std::make_unique<sf::RectangleShape>(collision.Target->GetShape()->getGlobalBounds().size);
    overlay->setPosition(collision.Target->GetShape()->getPosition());
    overlay->setFillColor(sf::Color(255, 0, 0, 50));
    m_Elements.emplace_back(std::move(overlay), duration);

    auto point = std::make_unique<sf::CircleShape>(3);
    point->setFillColor(sf::Color::Red);
    point->setOrigin(sf::Vector2f(1.f, 1.f));
    point->setPosition(collision.Position);
    m_Elements.emplace_back(std::move(point), duration);
#endif // _DEBUG
}

