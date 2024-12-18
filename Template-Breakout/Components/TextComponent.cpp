#include "TextComponent.h"

#include <iostream>
#include <string>
#include "../Services/GameManager.h"

#include "../resources.h"


TextComponent::TextComponent() 
{
	font = sf::Font(DEFAULT_FONT_PATH);
	text.setFillColor(sf::Color::White); // Couleur par défaut
	m_RenderWindow = I(GameManager)->GetWindow();
}

TextComponent::~TextComponent() 
{
}

void TextComponent::SetText(const std::string& content, unsigned int fontSize, const sf::Vector2f& position) 
{
	text.setString(content);
	text.setCharacterSize(fontSize);
	text.setPosition(position);
}

void TextComponent::SetColor(const sf::Color& color) 
{
	text.setFillColor(color);
}

void TextComponent::Draw() {
	if (m_RenderWindow) {
		m_RenderWindow->draw(text);
	}
}


