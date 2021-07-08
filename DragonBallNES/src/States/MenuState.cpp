#include "MenuState.h"

MenuState::MenuState(std::shared_ptr<sf::RenderWindow> window) : State(window)
{
	m_ButtonColors["Normal"] = sf::Color(50, 50, 50);
	m_ButtonColors["Hovered"] = sf::Color(70, 70, 70);
	m_ButtonColors["Pressed"] = sf::Color(40, 40, 40);

	m_Buttons["Play"] = std::make_shared<Button>(window);
	m_Texts["Play"] = std::make_shared<Text>(window);

	m_Buttons["Options"] = std::make_shared<Button>(window);
	m_Texts["Options"] = std::make_shared<Text>(window);
}

void MenuState::init()
{
	State::init();

	m_Buttons["Play"]->setSize(sf::Vector2f(200.f, 50.f));
	m_Buttons["Play"]->setShapeColor(m_ButtonColors["Normal"], "Normal");
	m_Buttons["Play"]->setShapeColor(m_ButtonColors["Hovered"], "Hovered");
	m_Buttons["Play"]->setShapeColor(m_ButtonColors["Pressed"], "Pressed");
	m_Buttons["Play"]->setPosition(sf::Vector2f(200, 100));

	m_Texts["Play"]->setFont("Resources/fonts/Chocolate_Cookies.ttf");
	m_Texts["Play"]->setText("Play");
	m_Texts["Play"]->setColor(sf::Color::White);
	m_Texts["Play"]->setSize(30);
	m_Texts["Play"]->setParent(m_Buttons["Play"]);

	m_Buttons["Options"]->setSize(sf::Vector2f(200.f, 50.f));
	m_Buttons["Options"]->setShapeColor(m_ButtonColors["Normal"], "Normal");
	m_Buttons["Options"]->setShapeColor(m_ButtonColors["Hovered"], "Hovered");
	m_Buttons["Options"]->setShapeColor(m_ButtonColors["Pressed"], "Pressed");
	m_Buttons["Options"]->setPosition(sf::Vector2f(200, 250.f));

	m_Texts["Options"]->setFont("Resources/fonts/Chocolate_Cookies.ttf");
	m_Texts["Options"]->setText("Options");
	m_Texts["Options"]->setColor(sf::Color::White);
	m_Texts["Options"]->setSize(30);
	m_Texts["Options"]->setParent(m_Buttons["Options"]);
}

void MenuState::updateEvents(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
		endState();
}

void MenuState::update(const float& dt)
{
	State::update(dt);

	for (std::pair<std::string, std::shared_ptr<Button>> b : m_Buttons)
		b.second->update(dt);
	for (std::pair<std::string, std::shared_ptr<Text>> t : m_Texts)
		t.second->update(dt);

	if (m_Buttons["Play"]->isClicked())
		pushState(std::make_shared<GameState>(m_Window));

	if (m_Buttons["Options"]->isClicked())
		LOG_TRACE("Clicked on Options button !");
}

void MenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (std::pair<std::string, std::shared_ptr<Button>> b : m_Buttons)
		target.draw(*b.second);
	for (std::pair<std::string, std::shared_ptr<Text>> t : m_Texts)
		target.draw(*t.second);
}
