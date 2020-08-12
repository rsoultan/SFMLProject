#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Core.hpp"
#include "Renderer.hpp"

Core::Core(std::string const &fontPath, sf::VideoMode const video, sf::String const title) noexcept : _window(std::make_unique<sf::RenderWindow>(video, title)), _renderer(std::make_unique<Renderer>(*_window.get()))
{
    _window->setFramerateLimit(60U);
    _font = std::make_unique<sf::Font>();
    _clock = std::make_unique<sf::Clock>();
    if (!_font->loadFromFile("./assets/Adventure Hollow.otf"))
        std::cerr << "[Core::Core] Failed to load font '" << fontPath << "'" << std::endl;
    _windowRatio.x = 1.0f;
    _windowRatio.y = 1.0f;
}

Core::~Core()
{

}

Renderer *Core::getRenderer() const noexcept
{
    return _renderer.get();
}

sf::RenderWindow *Core::getRenderWindow() const noexcept
{
    return _window.get();
}

sf::Clock *Core::getClock() const noexcept
{
    return _clock.get();
}

sf::Font *Core::getFont() const noexcept
{
    return _font.get();
}

sf::Vector2f Core::getWindowRatio() const noexcept
{
    return _windowRatio;
}

void Core::resizeWindow() noexcept
{
    sf::Vector2u const windowSize = _window->getSize();
    sf::Vector2u const originalSize(800U, 600U);

    _windowRatio.x = static_cast<float>(windowSize.x) / static_cast<float>(originalSize.x);
    _windowRatio.y = static_cast<float>(windowSize.y) / static_cast<float>(originalSize.y);
}