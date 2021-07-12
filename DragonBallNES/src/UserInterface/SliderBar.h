#pragma once

#include "Widget.h"
#include "Button.h"

class SliderBar : public Widget
{
public: //Constructors
	SliderBar(std::shared_ptr<sf::RenderWindow> window, const float& start, const float& end);
	SliderBar(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods
	virtual std::string log() const override { return "SlideBar"; }
	virtual void update(const float& dt) override;
	virtual void setPosition(const sf::Vector2f& pos) override;

	float getPercentage() const;
	float getValue() const;
	float getStartValue() const;
	float getEndValue() const;

	void setValue(const float& val);
	void setStart(const float& start);
	void setEnd(const float& end);

private: //Attributes
	std::shared_ptr<Button> m_Slider, m_Cursor;

	float m_Percentage;
	float m_Start, m_End;

	bool m_Grabbed;

private: //Private methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void updateRelativePosition() override;

	void grabCursor();
	void releaseCursor();

	void moveCursor(const float& percentage);

};

