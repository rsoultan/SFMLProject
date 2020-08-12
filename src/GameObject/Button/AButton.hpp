#ifndef ABUTTON_HPP
	#define ABUTTON_HPP
	#include <functional>
	#include <SFML/Graphics/Text.hpp>
	#include "IGameObject.hpp"
	class Core;
	class AButton : public IGameObject {
		public:
			AButton() = delete;
			AButton(sf::Font *font, sf::String const &str, sf::Vector2f const &pos, unsigned int const characterSize, std::function<void(Core *)> function);
			~AButton() = default;
			sf::Text getText() const;
			void update(float const elapsedTime);
			void event(Core *core, sf::Event const event);
		protected:
			std::function<void(Core *)> _function;
			sf::Text _text;
			float _elapsedTime;
	};
#endif