#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include "Display.h"

#include <vector>

using namespace sf;
extern Display display;

#ifndef Player_H
#define Player_H

class Player
{
	public:

		Player();
		~Player();

		void Movement(Event);
		void Shoot();
		void gameOver(Event);
		CircleShape getShape();
		void updateProjectiles(int);
		std::vector<CircleShape> getProjectiles();
		
	private:
		int lives;
		CircleShape shape;
		CircleShape projectile;
		std::vector<CircleShape> projectiles;
		Vector2f bounds;
};
#endif