#include "Text.h"

Text::Text(std::shared_ptr<sf::RenderWindow> window) : Widget(window)
{
	
}

void Text::update(const float& dt)
{
	Widget::update(dt);
	m_Text.setPosition(getAbsolutePosition());
}

void Text::setFont(const sf::Font& font)
{
	m_Text.setFont(font);
	updateBounds();
}

void Text::setText(const char* text)
{
	m_Text.setString(text);
	updateBounds();
}

void Text::setColor(const sf::Color& col) { m_Text.setFillColor(col); }

void Text::setSize(const unsigned int & size)
{
	m_Text.setCharacterSize(size);
	updateBounds();
}

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Widget::draw(target, states);
	target.draw(m_Text);
}

void Text::updateRelativeParent()
{
	Widget::updateRelativeParent();
	m_Text.setPosition(getAbsolutePosition());
}

void Text::updateBounds()
{
	m_Bounds = m_Text.getGlobalBounds();
}
