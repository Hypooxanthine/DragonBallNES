#include "GameState.h"

GameState::GameState(std::shared_ptr<sf::RenderWindow> window) : State(window)
{
}

void GameState::updateEvents(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
		endState();
}

void GameState::update(const float& dt)
{
	State::update(dt);
}

void GameState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
