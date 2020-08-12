#ifndef IGAMEOBJECT_HPP_
    #define IGAMEOBJECT_HPP_
	namespace sf {
		class Event;
	};
    class Core;
    class IGameObject {
        public:
            virtual void update(float const elapsedTime) = 0;
            virtual void event(Core *core, sf::Event const event) = 0;
    };
#endif