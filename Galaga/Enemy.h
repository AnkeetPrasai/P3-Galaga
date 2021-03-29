#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include "Player.h"

using namespace sf;

#ifndef Enemy_H
#define Enemy_H

class Enemy
{
public:
	Enemy();
	~Enemy();
	void Shoot();
	void updateProjectiles(int);
	std::vector<CircleShape> getProjectiles();

private:
	CircleShape shape;
	CircleShape projectile;
	std::vector<CircleShape> projectiles;
};
#endif