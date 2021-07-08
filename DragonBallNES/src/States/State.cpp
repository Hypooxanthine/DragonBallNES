#include "State.h"

State::State(std::shared_ptr<sf::RenderWindow> window)
{
	m_Window = window;
	m_IsPendingKill = false;
	m_IsPushingState = false;
	m_NextState = nullptr;
}

void State::init()
{
	LOG_INFO("Initialization of state {}.", log());
}

void State::update(const float& dt)
{
	updateMousePositions();
}

bool State::isPendingKill() { return m_IsPendingKill; }

bool State::isPushingState() { return m_IsPushingState; }

void State::endState() { m_IsPendingKill = true; }

void State::pushState(std::shared_ptr<State> state)
{
	m_IsPushingState = true; 
	m_NextState = state;
}

void State::updateMousePositions()
{
	m_MousePosScreen = sf::Mouse::getPosition();
	m_MousePosWindow = sf::Mouse::getPosition(*m_Window);
	m_MousePosView = m_Window->mapPixelToCoords(m_MousePosWindow);
}

std::shared_ptr<State> State::getNextState() {	return m_NextState; }

void State::resetPushedState()
{
	m_IsPushingState = false;
	m_NextState = nullptr;
}
