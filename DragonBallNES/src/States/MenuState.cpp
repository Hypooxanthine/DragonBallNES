#include "MenuState.h"

MenuState::MenuState(std::shared_ptr<sf::RenderWindow> window) : State(window)
{

}

void MenuState::updateEvents(sf::Event& e)
{
	if(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) //Has to be replaced with a Play button
		pushState(std::make_shared<GameState>(m_Window));
}

void MenuState::update(const float& dt)
{
	State::update(dt);
}

std::string MenuState::log()
{
	return "MenuState";
}

void MenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}
