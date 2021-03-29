#include "Enemy.h"

Enemy::Enemy()
{
	shape.setRadius(10.f);
}

Enemy::~Enemy()
{

}

void Enemy::Shoot()
{
	projectile.setPosition(shape.getPosition().x + 15, shape.getPosition().y + shape.getRadius());
	projectiles.push_back(CircleShape(projectile));
}

void Enemy::updateProjectiles(int i)
{
	projectiles[i].move(0, -10.f);
	if (projectiles[i].getPosition().y < 0)
	{
		projectiles.erase(projectiles.begin());
	}
}

std::vector<CircleShape> Enemy::getProjectiles()
{
	return projectiles;
}