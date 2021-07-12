#include "SliderBar.h"
#include "../Core/Math.h"

SliderBar::SliderBar(std::shared_ptr<sf::RenderWindow> window, const float& start, const float& end)
	: Widget(window), m_Slider(std::make_shared<Button>(window)), m_Cursor(std::make_shared<Button>(window)), m_Start(start), m_End(end), m_Percentage(0.5f), m_Grabbed(false)
{
	m_Cursor->setParent(m_Slider, false);

	m_Cursor->setCallbackPressed(BIND_CALLBACK_FN(SliderBar::grabCursor));
	m_Cursor->setCallbackReleased(BIND_CALLBACK_FN(SliderBar::releaseCursor));
	m_Slider->setCallbackPressed(BIND_CALLBACK_FN(SliderBar::grabCursor));
	m_Slider->setCallbackReleased(BIND_CALLBACK_FN(SliderBar::releaseCursor));

	std::map<std::string, sf::Color> cols;
	cols["Normal"] = sf::Color(50, 50, 50);
	cols["Hovered"] = sf::Color(70, 70, 70);
	cols["Pressed"] = sf::Color(40, 40, 40);

	m_Slider->setSize(sf::Vector2f(100.f, 10.f));
	m_Slider->setShapeColors(cols);

	m_Cursor->setSize(sf::Vector2f(20.f, 20.f));
	m_Cursor->setShapeColors(cols);

	moveCursor(0.5f);
}

SliderBar::SliderBar(std::shared_ptr<sf::RenderWindow> window)
	: SliderBar(window, 0.f, 1.f)
{
	
}

void SliderBar::update(const float& dt)
{
	Widget::update(dt);

	m_Slider->update(dt);
	m_Cursor->update(dt);

	if (m_Grabbed)
	{
		const sf::Vector2i& mousePos = getMousePosScreen();
		moveCursor(clamp(((float)mousePos.x - m_Bounds.left) / m_Slider->getBounds().width, 0.f, 1.f));
	}
}

void SliderBar::setPosition(const sf::Vector2f& pos)
{
	Widget::setPosition(pos);

	m_Slider->setPosition(pos);
}

float SliderBar::getPercentage() const
{
	return m_Percentage;
}

float SliderBar::getValue() const
{
	return (m_End - m_Start) * m_Percentage + m_Start;
}

float SliderBar::getStartValue() const
{
	return m_Start;
}

float SliderBar::getEndValue() const
{
	return m_End;
}

void SliderBar::setValue(const float& val)
{
	if (val >= m_Start && val <= m_End)
	{
		moveCursor((val - m_Start) / (m_End - m_Start));
	}
	else
		LOG_WARN("Tried to set out of bounds value in {}.", log());
}

void SliderBar::setStart(const float& start)
{
	m_Start = start;
}

void SliderBar::setEnd(const float& end)
{
	m_End = end;
}

void SliderBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Widget::draw(target, states);

	target.draw(*m_Slider);
	target.draw(*m_Cursor);
}

void SliderBar::updateRelativePosition()
{
	Widget::updateRelativePosition();
}

void SliderBar::grabCursor()
{
	m_Grabbed = true;
}

void SliderBar::releaseCursor()
{
	m_Grabbed = false;
}

void SliderBar::moveCursor(const float& percentage)
{
	m_Percentage = percentage;

	m_Cursor->setPosition(sf::Vector2f(m_Slider->getBounds().width * m_Percentage, -5.f));
}
