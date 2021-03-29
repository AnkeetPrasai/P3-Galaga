#include "Player.h"
#include "Display.h"
Display display;

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

void Player::Shoot(Event e)
{
    CircleShape projectile(50.f);
    projectile.setPosition(shape.getPosition());
    display.window.draw(projectile);
    FloatRect boundingBox = projectile.getGlobalBounds();
    while (boundingBox.contains(bounds) != true)
    {
        projectile.move(0, 200);
        display.window.draw(projectile);
    }
}
