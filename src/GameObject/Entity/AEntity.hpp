#ifndef AENTITY_HPP_
    #define AENTITY_HPP_
    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/System/Vector2.hpp>
    #include "IGameObject.hpp"
    namespace sf {
        class Texture;
    };
    class AEntity : public IGameObject {
        public:
            AEntity() = delete;
            AEntity(sf::Texture const &texture, sf::Vector2f const &position);
            void update(float const elapsedTime);
            void event(Core *core, sf::Event const event);
        protected:
            sf::Sprite _sprite;
    };
#endif