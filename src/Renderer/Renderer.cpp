#include <SFML/Graphics/RenderWindow.hpp>
#include "MenuButton.hpp"
#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow &renderWindow) : _renderer(renderWindow)
{

}

Renderer::~Renderer()
{

}

void Renderer::draw(Player const *player)
{
    //draw
}

void Renderer::draw(MenuButton const *button)
{
	if (!button->getText().getFont())
		return;
	_renderer.draw(button->getText());
}