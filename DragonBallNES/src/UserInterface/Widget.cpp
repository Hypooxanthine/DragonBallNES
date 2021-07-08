#include "Widget.h"

Widget::Widget(std::shared_ptr<sf::RenderWindow> window) : m_Window(window), m_ParentWidget(nullptr)
{
	m_CursorState = (isHovered() ? CursorState::StateHovered : CursorState::StateNormal);
	m_Clicked = false;
}

void Widget::update(const float& dt)
{
	updateState();
	updateRelativeParent();
}

bool Widget::isClicked(bool consume)
{
	if (!consume)
		return m_Clicked;
	else
	{
		if (m_Clicked)
		{
			m_Clicked = false;
			return true;
		}
		else
		{
			m_Clicked = false;
			return false;
		}
	}
}

void Widget::setParent(std::shared_ptr<Widget> parent)
{
	m_ParentWidget = parent;
}

sf::Vector2f Widget::getPosition() 
{ 
	if (m_ParentWidget == nullptr)
		return m_Position;
	else
		return m_Position + m_ParentWidget->getPosition();
}

void Widget::setPosition(const sf::Vector2f& pos) 
{ 
	m_Position = pos; 
}

void Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void Widget::onHovered()     {}
							 
void Widget::onStopHovered() {}
							 
void Widget::onPressed()     {}
							 
void Widget::onReleased()    {}
							 
void Widget::onClicked()     {}

bool Widget::isHovered()
{
	return m_Bounds.contains((float)getMousePosScreen().x, (float)getMousePosScreen().y);
}

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

void Widget::updateRelativeParent()
{
	if (m_ParentWidget != nullptr)
	{
		setPosition(m_ParentWidget->getPosition() + getPosition());
		m_Bounds.left = getPosition().x;
		m_Bounds.top = getPosition().y;
	}
}

sf::Vector2i Widget::getMousePosScreen()
{
	return sf::Mouse::getPosition(*m_Window);
}
