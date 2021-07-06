#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "../Core/Log.h"

class Widget : public sf::Drawable
{
public: //Enums
	enum class CursorState { StateNormal = 0, StateHovered, StatePressed, StatePressedUnhovered, StatePressedHovered};

public: //Constructors
	Widget(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods
	virtual void update(const float& dt);

	bool isClicked(bool consume = true);

protected: //Protected attributes
	std::shared_ptr<sf::RenderWindow> m_Window;

	sf::Vector2i m_MousePosScreen;
	CursorState m_CursorState;
	bool m_Clicked;

	sf::FloatRect m_Bounds;

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual void onHovered();
	virtual void onStopHovered();
	virtual void onPressed();
	virtual void onReleased();
	virtual void onClicked();

	bool isHovered();
	void updateState();

	sf::Vector2i getMousePosScreen();
};

