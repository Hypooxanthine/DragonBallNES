#pragma once

#include "Widget.h"

class Button : public Widget
{
public: //Constructors
	Button(std::shared_ptr<sf::RenderWindow> window);

protected: //Protected attributes
	sf::RectangleShape m_Shape;

protected: //PRotected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

