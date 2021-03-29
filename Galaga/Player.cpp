#include "Player.h"
#include "Display.h"
Display display;

Player::Player()
{
    shape.setRadius(50.f);
	shape.setPointCount(3);
	shape.setPosition(display.window.getSize().x / 2, display.window.getSize().y / 2);
	projectile.setRadius(10.f);
    lives = 3;
}

Player::~Player()
{

}

void Player::Movement(Event e)
{
        switch (e.key.code)
        {
		//AWDS 
        case Keyboard::A:
            shape.move(-100, 0);
			if (!music.openFromFile("MoveSound.ogg"))
				return; // error
			music.play();
            break;
        case Keyboard::W:
            shape.move(0, -100);
			if (!music.openFromFile("MoveSound.ogg"))
				return; // error
			music.play();
            break;
        case Keyboard::D:
            shape.move(100, 0);
			if (!music.openFromFile("MoveSound.ogg"))
				return; // error
			music.play();
            break;
        case Keyboard::S:
            shape.move(0, 100);
			if (!music.openFromFile("MoveSound.ogg"))
				return; // error
			music.play();
            break;

		//Up, Down, Left, Right mode
		case Keyboard::Left:
			shape.move(-100, 0);
			break;
		case Keyboard::Up:
			shape.move(0, -100);
			break;
		case Keyboard::Right:
			shape.move(100, 0);
			break;
		case Keyboard::Down:
			shape.move(0, 100);
			break;
        }

}

CircleShape Player::getShape()
{
    return shape;
}

void Player::Shoot()
{
	projectile.setPosition(shape.getPosition().x + 40, shape.getPosition().y + shape.getRadius());
	projectiles.push_back(CircleShape(projectile));
}

void Player::updateProjectiles(int i)
{
	projectiles[i].move(0, -10.f);
	if (projectiles[i].getPosition().y < 0)
	{
		projectiles.erase(projectiles.begin());
	}
}

std::vector<CircleShape> Player::getProjectiles()
{
	return projectiles;
}
