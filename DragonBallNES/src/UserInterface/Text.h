#pragma once

#include <SFML/Graphics.hpp>

#include "Widget.h"

class Text : public Widget
{
public: //Constructors
	Text(std::shared_ptr<sf::RenderWindow> window);

	void update(const float& dt) override;

public: //Public methods
	void setFont(const char* path);
	void setText(const char* text);

protected: //Protected attributes
	sf::Font m_Font;
	sf::Text m_Text;

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void updateRelativeParent() override;
};

