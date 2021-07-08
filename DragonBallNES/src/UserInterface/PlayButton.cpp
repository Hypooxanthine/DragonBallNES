#include "PlayButton.h"

PlayButton::PlayButton(std::shared_ptr<sf::RenderWindow> window) : Button(window)
{
	m_Shape = sf::RectangleShape(sf::Vector2f(50.f, 50.f));
	m_Shape.setFillColor(sf::Color::Red);

	m_Bounds.width = m_Shape.getGlobalBounds().width;
	m_Bounds.height = m_Shape.getGlobalBounds().height;

	setPosition(sf::Vector2f(200.f, 200.f));
}

void PlayButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Shape);
}