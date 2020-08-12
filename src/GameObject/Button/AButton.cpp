#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
#include "AButton.hpp"

AButton::AButton(sf::Font *font, sf::String const &str, sf::Vector2f const &pos, unsigned int const characterSize, std::function<void(Core *)> function)
{
	_text.setFont(*font);
	if (!_text.getFont())
		return;
	_text.setString(str);
	_text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
	_text.setPosition(pos);
	_text.setCharacterSize(characterSize);
	_text.setFillColor(sf::Color::White);
	_text.setOutlineColor(sf::Color::Black);
	_text.setOutlineThickness(2.5f);
	_elapsedTime = 0.0f;
	_function = function;
}

sf::Text AButton::getText() const
{
	return _text;
}

void AButton::update(float elapsedTime)
{
	_elapsedTime += elapsedTime;
}

void AButton::event(Core *core, sf::Event const event)
{

}