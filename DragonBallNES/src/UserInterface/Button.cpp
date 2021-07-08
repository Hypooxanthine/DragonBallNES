#include "Button.h"

Button::Button(std::shared_ptr<sf::RenderWindow> window) : Widget(window)
{
}

void Button::setPosition(const sf::Vector2f& pos)
{
	Widget::setPosition(pos);
	m_Shape.setPosition(getPosition());
}
