#pragma once

#include "Button.h"

class PlayButton : public Button
{
public: //Constructors
	PlayButton(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected: //Protected attributes

};

