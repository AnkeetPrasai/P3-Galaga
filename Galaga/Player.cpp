#include "Player.h"

Player::Player()
{
    shape.setRadius(50.f);
    lives = 3;
    bounds.x = 1280;
    bounds.y = 720;
}

Player::~Player()
{

}

void Player::Movement(Event e)
{
        switch (e.key.code)
        {
        case Keyboard::A:
            shape.move(-100, 0);
            break;
        case Keyboard::W:
            shape.move(0, -100);
            break;
        case Keyboard::D:
            shape.move(100, 0);
            break;
        case Keyboard::S:
            shape.move(0, 100);
            break;
        }
}

CircleShape Player::getShape()
{
    return shape;
}

void Player::Shoot(Event e)
{
    CircleShape projectile(50.f);
    projectile.setPosition(shape.getPosition());
    FloatRect boundingBox = projectile.getGlobalBounds();
    while (boundingBox.contains(bounds) != true)
    {
        projectile.move(0, 200);
    }
}
