#include "SettingsState.h"

SettingsState::SettingsState(std::shared_ptr<sf::RenderWindow> window) : State(window), m_Slider(std::make_shared<SliderBar>(window, 0.f, 1.f))
{
	m_Slider->setPosition(sf::Vector2f(50.f, 50.f));
}

void SettingsState::updateEvents(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
		endState();
}

void SettingsState::update(const float& dt)
{
	m_Slider->update(dt);
}

void SettingsState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_Slider);
}
