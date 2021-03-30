#include "Enemy.h"

Enemy::Enemy(int pos)
{
	shape.setRadius(10.f);
	shape.setPosition(pos, 0);
	position = pos;
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
	projectiles[i].move(0, 10.f);
	if (projectiles[i].getPosition().y < 0)
	{
		projectiles.erase(projectiles.begin());
	}
}

CircleShape Enemy::getShape()
{
	return shape;
}

std::vector<CircleShape> Enemy::getProjectiles()
{
	return projectiles;
}

void Enemy::move()
{
	shape.move(0, 10.f);
	if (shape.getPosition().y > 720)
	{
		shape.setPosition(position, 0);
	}
}