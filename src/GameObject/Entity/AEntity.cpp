#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "AEntity.hpp"

AEntity::AEntity(sf::Texture const &texture, sf::Vector2f const &pos)
{
    _sprite.setTexture(texture);
    //_sprite.setTextureRect();
}

void AEntity::update(float const elapsedTime)
{

}

void AEntity::event(Core *core, sf::Event const event)
{

}