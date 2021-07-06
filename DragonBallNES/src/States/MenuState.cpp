#include "MenuState.h"

MenuState::MenuState(std::shared_ptr<sf::RenderWindow> window) : State(window)
{

}

void MenuState::updateEvents(sf::Event& e)
{
	if(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
		pushState(std::make_shared<MenuState>(m_Window));
}

void MenuState::update(const float& dt)
{
	State::update(dt);
}

void MenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}
