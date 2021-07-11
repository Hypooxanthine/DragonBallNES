#include "MenuState.h"

MenuState::MenuState(std::shared_ptr<sf::RenderWindow> window) : State(window)
{
	m_ButtonColors["Normal"] = sf::Color(50, 50, 50);
	m_ButtonColors["Hovered"] = sf::Color(70, 70, 70);
	m_ButtonColors["Pressed"] = sf::Color(40, 40, 40);

	m_Buttons["Play"] = std::make_shared<Button>(window);
	m_Texts["Play"] = std::make_shared<Text>(window);

	m_Buttons["Settings"] = std::make_shared<Button>(window);
	m_Texts["Settings"] = std::make_shared<Text>(window);

	m_Buttons["Play"]->setCallbackClicked(BIND_CALLBACK_FN(MenuState::launchGame));
	m_Buttons["Settings"]->setCallbackClicked(BIND_CALLBACK_FN(MenuState::launchSettings));

	m_Buttons["Play"]->setSize(sf::Vector2f(200.f, 50.f));
	m_Buttons["Play"]->setShapeColors(m_ButtonColors);
	m_Buttons["Play"]->setPosition(sf::Vector2f(200.f, 100.f));

	m_Texts["Play"]->setText("Play");
	m_Texts["Play"]->setColor(sf::Color::White);
	m_Texts["Play"]->setSize(30);
	m_Texts["Play"]->setParent(m_Buttons["Play"]);

	m_Buttons["Settings"]->setSize(sf::Vector2f(200.f, 50.f));
	m_Buttons["Settings"]->setShapeColors(m_ButtonColors);
	m_Buttons["Settings"]->setPosition(sf::Vector2f(200.f, 250.f));

	m_Texts["Settings"]->setText("Options");
	m_Texts["Settings"]->setColor(sf::Color::White);
	m_Texts["Settings"]->setSize(30);
	m_Texts["Settings"]->setParent(m_Buttons["Settings"]);

	std::string path = "Resources/fonts/Chocolate_Cookies.ttf";
	LOG_INFO("Loading font from \"{}\".", path);
	if (!m_Font.loadFromFile(path))
		LOG_ERROR("Unable to load font !");
	else
	{
		LOG_INFO("Loaded font successfully.");
		m_Texts["Play"]->setFont(m_Font);
		m_Texts["Settings"]->setFont(m_Font);
	}
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
}

void MenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (std::pair<std::string, std::shared_ptr<Button>> b : m_Buttons)
		target.draw(*b.second);
	for (std::pair<std::string, std::shared_ptr<Text>> t : m_Texts)
		target.draw(*t.second);
}

void MenuState::launchGame()
{
	pushState(std::make_shared<GameState>(m_Window));
}

void MenuState::launchSettings()
{
	pushState(std::make_shared<SettingsState>(m_Window));
}
