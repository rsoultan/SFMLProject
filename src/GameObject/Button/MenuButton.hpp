#ifndef MENUBUTTON_HPP
	#define MENUBUTTON_HPP
	#include "AButton.hpp"
	namespace sf {
		class String;
	};
	class MenuButton : public AButton {
		public:
			MenuButton(sf::Font *font, sf::String const &str, sf::Vector2f const &pos, unsigned int const characterSize, std::function<void(Core *)> function);
			~MenuButton() = default;
			void update(sf::RenderWindow &window, sf::Vector2f windowRatio, float const seconds);
			void event(Core *core, sf::Event const event);
	};
#endif