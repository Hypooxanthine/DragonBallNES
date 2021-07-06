#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

class Widget
{
public: //Constructors
	Widget(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods

protected: //Protected attributes
	std::shared_ptr<sf::RenderWindow> m_Window;

	sf::Vector2u m_MousePosScreen, m_LastMousePosScreen;

protected: //Protected methods
	virtual void onHovered() = 0;
	virtual void onStopHovered() = 0;
	virtual void onPressed() = 0;
	virtual void onReleased() = 0;
	virtual void onClicked() = 0;
};

