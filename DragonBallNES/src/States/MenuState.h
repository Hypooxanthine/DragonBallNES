#pragma once

#include "States.h"

class MenuState : public State
{
public: //Constructors
	MenuState(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods
	virtual void updateEvents(sf::Event& e) override;
	virtual void update(const float& dt) override;

private: //Attributes

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

