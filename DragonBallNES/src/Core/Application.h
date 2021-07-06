#pragma once

#include <iostream>
#include <stack>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Log.h"
#include "../States/States.h"

class Application
{
public: //Constructors

public: //Public methods
	Application(const char* windowTitle = "Dragon Ball NES");

private: //Attributes
	/* Window */
	std::shared_ptr<sf::RenderWindow> m_Window;

	/* Delta Time */
	float m_Dt;
	sf::Clock m_DtClock;

	/* Events */
	sf::Event m_Event;

	/* States */
	std::stack<std::shared_ptr<State>> m_States;

private: //Private methodes
	/* Main loop */
	void run(const char* windowTitle);
	void updateEvents();
	void render();
	void updateState();
	void updateDt();

	/* States */
	bool isTopStateValid();
};
