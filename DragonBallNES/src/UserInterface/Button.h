#pragma once

#include <map>

#include "Widget.h"

class Button : public Widget
{
public: //Constructors
	Button(std::shared_ptr<sf::RenderWindow> window);

public: //Public methods
	virtual std::string log() const override { return "Button"; };

	void setSize(sf::Vector2f size);

	virtual void update(const float& dt) override;

	virtual void setPosition(const sf::Vector2f& pos) override;
	void setShapeColor(sf::Color col, std::string key);
	void setShapeColors(std::map<std::string, sf::Color> cols);

protected: //Protected attributes
	std::map<std::string, sf::RectangleShape> m_Shapes;
	sf::RectangleShape* m_ActiveShape;

protected: //Protected methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void updateRelativePosition() override;

	void updateActiveShape();
};

