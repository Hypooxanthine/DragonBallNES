#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "../Core/Log.h"

//#define BIND_CALLBACK_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
#define BIND_CALLBACK_FN(fn) [this]() { return this->fn(); } //Seems to do the same with a void function with no argument

/// <summary>
/// Methods that have to be overriden :
/// void draw(const sf::RenderTarget&, sf::RenderStates states) const
/// std::string log()
/// </summary>
class Widget : public sf::Drawable, public Loggable
{
public: //Enums
	enum class CursorState { StateNormal = 0, StateHovered, StatePressed, StatePressedUnhovered, StatePressedHovered };

public: //Constructors
	Widget(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods
	virtual void update(const float& dt);

	void setParent(std::shared_ptr<Widget> parent, bool center = true);

	sf::Vector2f getAbsolutePosition();
	sf::Vector2f getRelativePosition();
	virtual void setPosition(const sf::Vector2f& pos);

	sf::Vector2f getCenter();
	sf::FloatRect getBounds() const;

	//Callback functions
	using CallbackFn = std::function<void()>;

	void setCallbackClicked(const CallbackFn& fn) { m_CallbackFns["Clicked"] = fn; }
	void setCallbackHovered(const CallbackFn& fn) { m_CallbackFns["Hovered"] = fn; }
	void setCallbackStopHovered(const CallbackFn& fn) { m_CallbackFns["StopHovered"] = fn; }
	void setCallbackPressed(const CallbackFn& fn) { m_CallbackFns["Pressed"] = fn; }
	void setCallbackReleased(const CallbackFn& fn) { m_CallbackFns["Released"] = fn; }

protected: //Protected attributes
	std::shared_ptr<sf::RenderWindow> m_Window;

	sf::Vector2i m_MousePosScreen;
	CursorState m_CursorState;
	bool m_Clicked;

	sf::FloatRect m_Bounds;

	sf::Vector2f m_Position;

	std::shared_ptr<Widget> m_ParentWidget;
	bool m_Center;

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual void onHovered();
	virtual void onStopHovered();
	virtual void onPressed();
	virtual void onReleased();
	virtual void onClicked();

	bool isHovered();
	void updateState();
	virtual void updateRelativePosition();

	sf::Vector2i getMousePosScreen();

private: //Private attributes
	std::map<std::string, CallbackFn> m_CallbackFns;

};