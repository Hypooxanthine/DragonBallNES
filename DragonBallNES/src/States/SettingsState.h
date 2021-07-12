#pragma once

#include <map>

#include "States.h"
#include "../UserInterface/SliderBar.h"

class SettingsState : public State
{
public: //Constructors
	SettingsState(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods
	virtual std::string log() const override { return "SettingsState"; };
	virtual void updateEvents(sf::Event& e) override;
	virtual void update(const float& dt) override;

private: //Attributes
	std::shared_ptr<SliderBar> m_Slider;

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

