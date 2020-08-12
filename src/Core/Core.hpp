#ifndef CORE_HPP_
    #define CORE_HPP_
    #include <string>
    #include <memory>
    #include <SFML/System/Vector2.hpp>
    namespace sf {
        class VideoMode;
        class String;
        class RenderWindow;
        class Clock;
        class Font;
    };
    class Renderer;
    class Core {
        public:
            Core() = delete;
            Core(std::string const &fontPath, sf::VideoMode video, sf::String title) noexcept;
            Core(Core const &other) = delete;
            ~Core();
            Renderer *getRenderer() const noexcept;
            sf::RenderWindow *getRenderWindow() const noexcept;
            sf::Clock *getClock() const noexcept;
            sf::Font *getFont() const noexcept;
            sf::Vector2f getWindowRatio() const noexcept;
            void resizeWindow() noexcept;
        private:
            std::unique_ptr<sf::RenderWindow> _window;
            std::unique_ptr<Renderer> _renderer;
            std::unique_ptr<sf::Clock> _clock;
            std::unique_ptr<sf::Font> _font;
            sf::Vector2f _windowRatio;
    };
#endif