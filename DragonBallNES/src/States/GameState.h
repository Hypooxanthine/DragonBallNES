#pragma once

#include "States.h"

class GameState : public State
{
public: //Constructors
	GameState(std::shared_ptr<sf::RenderWindow> window);
	
public: //Public methods
	virtual void updateEvents(sf::Event& e) override = 0;
	virtual void update(const float& dt) override;

private: //Attributes

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

