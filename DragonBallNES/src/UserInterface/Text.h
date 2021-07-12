#pragma once

#include <SFML/Graphics.hpp>

#include "Widget.h"

class Text : public Widget
{
public: //Constructors
	Text(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods
	virtual std::string log() const override { return "Text(\"" + m_Text.getString() + "\")"; }

	virtual void update(const float& dt) override;

	void setFont(const sf::Font& font);
	void setText(const char* text);
	void setColor(const sf::Color& col);
	void setSize(const unsigned int & size);

protected: //Protected attributes
	sf::Text m_Text;

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void updateRelativePosition() override;

	void updateBounds();
};

