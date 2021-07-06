#include "Application.h"

Application::Application(const char* windowTitle)
{
	m_Window = std::make_shared<sf::RenderWindow>();
	m_States.push(std::make_shared<MenuState>(m_Window));
	m_Dt = 0.f;

	run(windowTitle);
}

void Application::run(const char* windowTitle)
{
	m_Window->create(sf::VideoMode(600, 400, 32), windowTitle);

	m_DtClock.restart();

	while (m_Window->isOpen())
	{
		updateEvents();
		updateStates();
		render();
		checkState();
		updateDt();
	}
}

void Application::updateEvents()
{
	while (m_Window->pollEvent(m_Event))
	{
		if (m_Event.type == sf::Event::Closed)
			m_Window->close();

		if (isTopStateValid())
			m_States.top()->updateEvents(m_Event);
	}
}

void Application::updateStates()
{
	if(isTopStateValid())
		m_States.top()->update(m_Dt);
}

void Application::render()
{
	m_Window->clear();

	//Render stuff here
	if(isTopStateValid())
		m_Window->draw(*m_States.top());

	m_Window->display();
}

void Application::checkState()
{
	if (isTopStateValid() && m_States.top()->isPendingKill())
		m_States.pop();
	else if (isTopStateValid() && m_States.top()->isPushingState())
	{
		std::shared_ptr<State> nextState = m_States.top()->getNextState();
		m_States.top()->resetPushedState();

		if (nextState != nullptr)
		{
			LOG_INFO("Pushing a new state.");
			m_States.push(nextState);
		}
		else
			LOG_ERROR("State is pushing an invalid state.");
	}

	if (!isTopStateValid())
		m_Window->close();
}

void Application::updateDt()
{
	m_Dt = m_DtClock.restart().asSeconds();
}

bool Application::isTopStateValid()
{
	return !m_States.empty() && m_States.top() != nullptr;
}
