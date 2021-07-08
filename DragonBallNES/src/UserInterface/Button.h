#pragma once

#include "Widget.h"

class Button : public Widget
{
public: //Constructors
	Button(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods
	virtual void setPosition(const sf::Vector2f& pos) override;

protected: //Protected attributes
	sf::RectangleShape m_Shape;

protected: //Protected methods
};

