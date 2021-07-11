#include "SettingsState.h"

SettingsState::SettingsState(std::shared_ptr<sf::RenderWindow> window) : State(window) {}

void SettingsState::updateEvents(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
		endState();
}

void SettingsState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
}
