#include "Text.h"

Text::Text(std::shared_ptr<sf::RenderWindow> window) : Widget(window)
{
	m_Text.setFillColor(sf::Color::White);
	m_Text.setCharacterSize(64);
}

void Text::update(const float& dt)
{
	Widget::update(dt);
	m_Text.setPosition(getPosition());
	//LOG_TRACE("{}, {}", getPosition().x, getPosition().y);
}

void Text::setFont(const char* path)
{
	LOG_INFO("Loading font from \"{}\".", path);
	if (!m_Font.loadFromFile(path))
	{
		LOG_ERROR("Unable to load font !");
	}
	else
	{
		LOG_INFO("Loaded font successfully.");
		m_Text.setFont(m_Font);
	}
}

void Text::setText(const char* text)
{
	m_Text.setString(text);
}

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Widget::draw(target, states);
	target.draw(m_Text);
}

void Text::updateRelativeParent()
{
	Widget::updateRelativeParent();
	m_Text.setPosition(getPosition());
}
