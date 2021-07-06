#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "../Core/Log.h"

class State : public sf::Drawable, public Loggable
{
public: //Constructors
	State(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods
	/* Updating */
	virtual void updateEvents(sf::Event& e) = 0;
	virtual void update(const float& dt);

	/* Ending state */
	bool isPendingKill();
	bool isPushingState();

	/// <summary>
	/// You should use void State::resetPushedState() after handling the pushed state to reset it.
	/// </summary>
	/// <returns></returns>
	std::shared_ptr<State> getNextState();
	void resetPushedState();

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

	/* Ending state */
	virtual void endState();
	void pushState(std::shared_ptr<State> state);

	/* Mouse position */
	void updateMousePositions();

protected: //Protected attributes
	std::shared_ptr<sf::RenderWindow> m_Window;
	
	/* Ending state */
	bool m_IsPendingKill;
	bool m_IsPushingState;
	std::shared_ptr<State> m_NextState;

	/* Mouse position */
	sf::Vector2i m_MousePosScreen;
	sf::Vector2i m_MousePosWindow;
	sf::Vector2f m_MousePosView;
};

