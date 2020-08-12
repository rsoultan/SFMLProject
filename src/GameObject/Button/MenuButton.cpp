#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
#include "MenuButton.hpp"
#include "Core.hpp"

MenuButton::MenuButton(sf::Font *font, sf::String const &str, sf::Vector2f const &pos, unsigned int const characterSize, std::function<void(Core *)> function) : AButton(font, str, pos, characterSize, function)
{

}

void MenuButton::update(sf::RenderWindow &window, sf::Vector2f windowRatio, float const seconds)
{
    _elapsedTime += seconds;
    if (_elapsedTime <= 0.5)
        return;
    _elapsedTime = 0.0f;
	sf::FloatRect collision = _text.getGlobalBounds();
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f vector(mousePosition.x, mousePosition.y);
    collision.height *= windowRatio.y;
    collision.left *= windowRatio.x;
    collision.width *= windowRatio.x;
    collision.top *= windowRatio.y;
    if (collision.contains(vector)) {
		_text.setFillColor(sf::Color::Blue);
        unsigned int characterSize = _text.getCharacterSize();
        if (characterSize >= 60U)
            return;
        _text.setCharacterSize(++characterSize);
        _text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
    } else {
		_text.setFillColor(sf::Color::White);
        unsigned int characterSize = _text.getCharacterSize();
        if (characterSize <= 30U)
            return;
        _text.setCharacterSize(--characterSize);
        _text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
    }
}

void MenuButton::event(Core *core, sf::Event const event)
{
	sf::FloatRect collision = _text.getGlobalBounds();
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*core->getRenderWindow());
	sf::Vector2f vector(mousePosition.x, mousePosition.y);

    collision.height *= core->getWindowRatio().y;
    collision.left *= core->getWindowRatio().x;
    collision.width *= core->getWindowRatio().x;
    collision.top *= core->getWindowRatio().y;
	if (collision.contains(vector)) {
        if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            std::printf("1\n");
        } else if (event.type == sf::Event::MouseButtonReleased) {
            std::printf("2\n");
            _function(core);
        }
	}
}