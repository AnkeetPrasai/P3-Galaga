#include "Player.h"
Display display;

Player::Player()
{
    shape.setRadius(20.f);
	shape.setPointCount(3);
	shape.setPosition(display.window.getSize().x / 2, 700);
	projectile.setRadius(5.f);
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
            shape.move(-40, 0);
			if (!music.openFromFile("MoveSound.ogg"))
				return; // error
			music.play();
            break;
        case Keyboard::W:
            shape.move(0, -40);
			if (!music.openFromFile("MoveSound.ogg"))
				return; // error
			music.play();
            break;
        case Keyboard::D:
            shape.move(40, 0);
			if (!music.openFromFile("MoveSound.ogg"))
				return; // error
			music.play();
            break;
        case Keyboard::S:
            shape.move(0, 40);
			if (!music.openFromFile("MoveSound.ogg"))
				return; // error
			music.play();
            break;

		//Up, Down, Left, Right mode
		case Keyboard::Left:
			shape.move(-40, 0);
			break;
		case Keyboard::Up:
			shape.move(0, -40);
			break;
		case Keyboard::Right:
			shape.move(40, 0);
			break;
		case Keyboard::Down:
			shape.move(0, 40);
			break;
        }

		//Keeps track if the player ends up off the screen
		if (shape.getPosition().x < 0)
		{
			shape.setPosition(1280, shape.getPosition().y); //Resets if the player goes off the left side
		}
		else if (shape.getPosition().x > 1280)
		{
			shape.setPosition(0, shape.getPosition().y); //Resets if the player goes off the right side
		}
		else if (shape.getPosition().y < 0)
		{
			shape.setPosition(shape.getPosition().x, 720); //Resets if the player goes off the top
		}
		else if (shape.getPosition().y > 720)
		{
			shape.setPosition(shape.getPosition().x, 0); //Resets if the player goes off the bottom
		}
}

CircleShape Player::getShape()
{
    return shape;
}

void Player::Shoot()
{
	projectile.setPosition(shape.getPosition().x + 15, shape.getPosition().y + shape.getRadius());
	projectiles.push_back(CircleShape(projectile));
}

void Player::updateProjectiles(int i, std::vector<Enemy> &e)
{
	projectiles[i].move(0, -10.f);
	Rect<float> p(projectiles[i].getPosition().x, projectiles[i].getPosition().y, 10.f, 10.f);
	for (int j = 0; j < e.size(); j++)
	{
		Rect<float> en(e[j].getShape().getPosition().x, e[j].getShape().getPosition().y, 10.f, 10.f);
		if (p.intersects(en))
		{
			e.erase(e.begin() + j);
		}
	}
	if (projectiles[i].getPosition().y < 0)
	{
		projectiles.erase(projectiles.begin());
	}
}

std::vector<CircleShape> Player::getProjectiles()
{
	return projectiles;
}

bool Player::checkCollison(Enemy e)
{
	bool collison = false;
	Rect<float> p(shape.getPosition().x, shape.getPosition().y, 40.f, 40.f);
	Rect<float> en(e.getShape().getPosition().x, e.getShape().getPosition().y, 10.f, 10.f);
	if (p.intersects(en))
	{
		lives--;
		shape.setPosition(display.window.getSize().x / 2, 700);
		e.getShape().setPosition(e.getPosition(), 0);
		collison = true;
	}
	return collison;
}
