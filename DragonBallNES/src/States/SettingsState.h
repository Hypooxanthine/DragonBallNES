#pragma once

#include "States.h"

class SettingsState : public State
{
public: //Constructors
	SettingsState(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods
	virtual void updateEvents(sf::Event& e) override;
	virtual std::string log() override { return "SettingsState"; };

private: //Attributes

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

