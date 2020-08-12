#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include "MenuButton.hpp"
#include "Core.hpp"
#include "Renderer.hpp" 

void playGame(Core *game)
{

}

void quitGame(Core *engine)
{
    engine->getRenderWindow()->close();
}

int main(void)
{
    std::unique_ptr<Core> engine = std::make_unique<Core>(
        "assets/Adventure Hollow.otf",
        sf::VideoMode(800U, 600U),
        sf::String(L"Test")
    );
    MenuButton *playGame = new MenuButton(
        engine->getFont(),
        sf::String(L"Play Game"),
        sf::Vector2f(50.0f * engine->getRenderWindow()->getSize().x / 100.0f, 50.0f * engine->getRenderWindow()->getSize().y / 100.0f),
        30U,
        quitGame
    );
    MenuButton *exitButton = new MenuButton(
        engine->getFont(),
        sf::String(L"Exit"),
        sf::Vector2f(50.0f * engine->getRenderWindow()->getSize().x / 100.0f, 60.0f * engine->getRenderWindow()->getSize().y / 100.0f),
        30U,
        quitGame
    );
    sf::Event event;
    while (engine->getRenderWindow()->isOpen()) {
        while (engine->getRenderWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                engine->getRenderWindow()->close();
            if (event.type == sf::Event::Resized)
                engine->resizeWindow();
            playGame->event(engine.get(), event);
            exitButton->event(engine.get(), event);
        }
        engine->getRenderWindow()->clear();
        playGame->update(*engine->getRenderWindow(), engine->getWindowRatio(), engine->getClock()->getElapsedTime().asSeconds());
        exitButton->update(*engine->getRenderWindow(), engine->getWindowRatio(), engine->getClock()->getElapsedTime().asSeconds());
        engine->getRenderer()->draw(playGame);
        engine->getRenderer()->draw(exitButton);
        engine->getRenderWindow()->display();
    }
    return EXIT_SUCCESS;
}