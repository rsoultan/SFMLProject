#ifndef RENDERER_HPP_
    #define RENDERER_HPP_
    namespace sf {
        class RenderWindow;
    };
    class Player;
    class MenuButton;
    class Renderer {
        public:
            Renderer(sf::RenderWindow &renderWindow);
            ~Renderer();
            void draw(Player const *player);
            void draw(MenuButton const *button);
        private:
            sf::RenderWindow &_renderer;
    };
#endif