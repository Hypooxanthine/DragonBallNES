#include "Widget.h"

Widget::Widget(std::shared_ptr<sf::RenderWindow> window) : m_Window(window), m_ParentWidget(nullptr)
{
	m_CursorState = (isHovered() ? CursorState::StateHovered : CursorState::StateNormal);
	m_Clicked = false;
}

void Widget::update(const float& dt)
{
	updateRelativePosition();
	updateState();
}

void Widget::setParent(std::shared_ptr<Widget> parent, bool center)
{
	m_ParentWidget = parent;
	m_Center = center;
}

sf::Vector2f Widget::getAbsolutePosition() 
{ 
	if (m_ParentWidget == nullptr)
		return m_Position;
	else
		return m_Position + m_ParentWidget->getAbsolutePosition()
		       + (m_Center ? m_ParentWidget->getCenter() - getCenter() : sf::Vector2f());
}

sf::Vector2f Widget::getRelativePosition()
{
	return m_Position;
}

void Widget::setPosition(const sf::Vector2f& pos) 
{ 
	m_Position = pos; 
	m_Bounds.left = pos.x;
	m_Bounds.top = pos.y;
}

sf::Vector2f Widget::getCenter()
{
	sf::Vector2f pos;

	pos.x += m_Bounds.width / 2.f;
	pos.y += m_Bounds.height / 2.f;

	return pos;
}

sf::FloatRect Widget::getBounds() const
{
	return m_Bounds;
}

void Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void Widget::onHovered() 
{
	if (m_CallbackFns.find("Hovered") != m_CallbackFns.end())
		m_CallbackFns["Hovered"]();
}
							 
void Widget::onStopHovered()
{
	if (m_CallbackFns.find("StopHovered") != m_CallbackFns.end())
		m_CallbackFns["StopHovered"]();
}
							 
void Widget::onPressed()
{
	if (m_CallbackFns.find("Pressed") != m_CallbackFns.end())
		m_CallbackFns["Pressed"]();
}
							 
void Widget::onReleased()
{
	if (m_CallbackFns.find("Released") != m_CallbackFns.end())
		m_CallbackFns["Released"]();
}
							 
void Widget::onClicked()
{
	if (m_CallbackFns.find("Clicked") != m_CallbackFns.end())
		m_CallbackFns["Clicked"]();
}

bool Widget::isHovered() { return m_Bounds.contains((sf::Vector2f)sf::Mouse::getPosition(*m_Window)); }

void Widget::updateState()
{
	switch (m_CursorState)
	{
	case CursorState::StateNormal: //If state was normal
		if (isHovered()) //If mouse is hovering widget
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If LMB is pressed
			{
				m_CursorState = CursorState::StatePressedHovered;
			}
			else
			{
				m_CursorState = CursorState::StateHovered;
			}

			onHovered();
		}

		break;
	case CursorState::StateHovered: //If state was hovered
		if (isHovered()) //If mouse is stil hovering widget
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If LMB is pressed
			{
				m_CursorState = CursorState::StatePressed;
				onPressed();
			}
		}
		else //If mouse is no longer hovering widget
		{
			m_CursorState = CursorState::StateNormal;
			onStopHovered();
		}
		break;
	case CursorState::StatePressed: //If state was pressed
		if (isHovered()) //If mouse is hovering widget
		{
			if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If LMB is no longer pressed
			{
				m_CursorState = CursorState::StateHovered;
				m_Clicked = true;
				onReleased();
				onClicked();
			}
		}
		else //If mouse isn't hovering widget
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If LMB is still pressed
			{
				m_CursorState = CursorState::StatePressedUnhovered;
			}
			else
			{
				m_CursorState = CursorState::StateNormal;
			}

			onStopHovered();
		}
		break;
	case CursorState::StatePressedUnhovered:
		if (isHovered()) //If mouse is hovering widget
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If LMB is pressed
			{
				m_CursorState = CursorState::StatePressed;
			}
			else //If LMB isn't pressed
			{
				m_CursorState = CursorState::StateHovered;
				onReleased();
			}

			onHovered();
		}
		else //If mouse isn't hovering widget
		{
			if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If LMB isn't pressed
			{
				m_CursorState = CursorState::StateNormal;
				onReleased();
			}
		}

		break;
	case CursorState::StatePressedHovered:
		if (isHovered()) //If mouse is hovering widget
		{
			if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If LMB isn't pressed
			{
				m_CursorState = CursorState::StateHovered;
			}
		}
		else //If mouse isn't hovering widget
		{
			m_CursorState = CursorState::StateNormal;
			onStopHovered();
		}

		break;
	}
}

void Widget::updateRelativePosition() 
{
	const sf::Vector2f& pos = getAbsolutePosition();

	m_Bounds.left = pos.x;
	m_Bounds.top = pos.y;
}

sf::Vector2i Widget::getMousePosScreen()
{
	return sf::Mouse::getPosition(*m_Window);
}
