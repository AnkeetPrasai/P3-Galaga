#include <iostream>
#include "Player.h"
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

private:
	CircleShape shape;
	CircleShape projectile;
	std::vector<CircleShape> projectiles;
	int position;
};
#endif