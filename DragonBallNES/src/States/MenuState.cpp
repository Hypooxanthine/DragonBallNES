#include "MenuState.h"

MenuState::MenuState(std::shared_ptr<sf::RenderWindow> window) : State(window), m_PlayButton(Button(window))
{
	
}

void MenuState::updateEvents(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
		endState();
}

void MenuState::update(const float& dt)
{
	State::update(dt);
	m_PlayButton.update(dt);

	if (m_PlayButton.isClicked())
		pushState(std::make_shared<GameState>(m_Window));
}

std::string MenuState::log()
{
	return "MenuState";
}

void MenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_PlayButton);
}
