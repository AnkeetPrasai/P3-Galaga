#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"

using namespace sf;

#ifndef Player_H
#define Player_H

class Player
{
	public:

		Player();
		~Player();

		void Movement(Event);
		void Shoot(Event);
		void gameOver(Event);
		CircleShape getShape();
		
	private:
		int lives;
		CircleShape shape;
		Vector2f bounds;
};
#endif