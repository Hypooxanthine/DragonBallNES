#include "MenuState.h"

MenuState::MenuState(std::shared_ptr<sf::RenderWindow> window) :
	State(window), m_PlayButton(std::make_shared<Button>(window)), m_PlayText(std::make_shared<Text>(window))
{}

void MenuState::init()
{
	State::init();

	m_PlayButton->setSize(sf::Vector2f(100.f, 50.f));
	m_PlayButton->setShapeColor(sf::Color::Red, "Normal");
	m_PlayButton->setShapeColor(sf::Color::Magenta, "Hovered");
	m_PlayButton->setShapeColor(sf::Color::White, "Pressed");
	m_PlayButton->setRelativePosition(sf::Vector2f(200.f, 200.f));

	m_PlayText->setFont("Resources/fonts/Chocolate_Cookies.ttf");
	m_PlayText->setText("Play");
	m_PlayText->setColor(sf::Color::White);
	m_PlayText->setSize(30);
	m_PlayText->setParent(m_PlayButton);
}

void MenuState::updateEvents(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
		endState();
}

void MenuState::update(const float& dt)
{
	State::update(dt);

	m_PlayButton->update(dt);
	m_PlayText->update(dt);

	if (m_PlayButton->isClicked())
		pushState(std::make_shared<GameState>(m_Window));
}

void MenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_PlayButton);
	target.draw(*m_PlayText);
}
