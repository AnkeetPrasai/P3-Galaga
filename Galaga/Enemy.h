#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
using namespace sf;

#ifndef Enemy_H
#define Enemy_H

class Enemy
{
public:
	Enemy(int);
	~Enemy();
	void Shoot();
	void updateProjectiles(int);
	std::vector<CircleShape> getProjectiles();
	CircleShape getShape();
	void move();
	int getPosition();

private:
	CircleShape shape;
	CircleShape projectile;
	std::vector<CircleShape> projectiles;
	int position;
};
#endif