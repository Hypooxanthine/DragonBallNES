#include "Button.h"

Button::Button(std::shared_ptr<sf::RenderWindow> window) : Widget(window)
{
	m_Shape = sf::RectangleShape(sf::Vector2f(50.f, 50.f));
	m_Shape.setPosition(200.f, 200.f);
	m_Shape.setFillColor(sf::Color::Red);

	m_Bounds = m_Shape.getGlobalBounds();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Shape);
}
