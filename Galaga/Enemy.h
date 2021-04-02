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
	Enemy(int, int);
	~Enemy();
	void Shoot();
	void updateProjectiles(int);
	std::vector<CircleShape> getProjectiles();
	CircleShape getShape();
	void move();
	int getPosition();
	void backAndForth(bool);

private:
	CircleShape shape;
	CircleShape projectile;
	std::vector<CircleShape> projectiles;
	int startX, startY;
};
#endif