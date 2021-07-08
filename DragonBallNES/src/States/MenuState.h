#pragma once

#include "States.h"
#include "../UserInterface/PlayButton.h"
#include "../UserInterface/Text.h"

class MenuState : public State
{
public: //Constructors
	MenuState(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods
	virtual void updateEvents(sf::Event& e) override;
	virtual void update(const float& dt) override;
	virtual std::string log() override;

private: //Attributes
	std::shared_ptr<PlayButton> m_PlayButton;
	std::shared_ptr<Text> m_PlayText;

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

