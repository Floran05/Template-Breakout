#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>


class TextComponent : public Component 
{
public:
	TextComponent();
	~TextComponent();

	void SetText(const std::string& content, unsigned int fontSize, const sf::Vector2f& position);

	void SetColor(const sf::Color& color);

	virtual void Draw() override;

private:
	sf::Font font;	
	sf::Text text = sf::Text(font, "hello");

	sf::RenderWindow* m_RenderWindow = nullptr; // Référence à la fenêtre de rendu SFML
};