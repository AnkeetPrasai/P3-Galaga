#include <iostream>
#include "Player.h"
#include "Enemy.h"
using namespace sf;
using namespace std;

void StartScreen()
{
  // display.window.clear(sf::Color::Black);
  // sf::Image image1;
  // image1.create(1280 , 720);//1280 , 720
  // for (int i = 0; i < 1280; i++)
  // {
  //   for (int j = 0; j < 720; j++)
  //   {
  //   //  if (i % 30 == 0 || j % 30 == 0)
  //   //  {
  //   //    image1.setPixel(i,j, sf::Color::Red);
  //   //    }
  //   if (i > 256 && i < 1024 && j > 100 && j < 360)
  //   {
  //       image1.setPixel(i,j, sf::Color::Magenta);
  //   }
  //     else
  //     {
  //     image1.setPixel(i,j, sf::Color::Black);
  //     }
  //   }
  // }
  sf::Texture galagaLogo;
  sf::Sprite galagaScreen;

  sf::Texture pushSpaceKey;
  sf::Sprite spaceKeyScreen;


  if (!galagaLogo.loadFromFile("GalagaLogo.png"))
  {
    cout << "Could not load Galaga image";
  }

  galagaScreen.setTexture(galagaLogo);

  if (!pushSpaceKey.loadFromFile("pushSpaceKey.jpg"))
  {
    cout << "Could not load push space key image";
  }
  spaceKeyScreen.setTexture(pushSpaceKey);


  // sf::Texture texture1;
  // texture1.loadFromImage(image1);
  // sf::Sprite sprite1(texture1);
  display.window.draw(galagaScreen);
  display.window.draw(spaceKeyScreen);
  // display.window.draw(sprite1);

  display.window.display();

  while (display.window.isOpen())
  {
      Event e;
      // Checks for any input from user and it send it to event handler
      while (display.window.pollEvent(e))
      {
          if (e.type == Event::KeyPressed)
          {
            if (e.key.code == Keyboard::Space)
            {
              display.window.clear();
              return;
            }
          }
      }
  }
}

int main()
{
  int check = 1;
  sf::Music music;
  if (!music.openFromFile("GalagaTheme.ogg"))
  {
      return -1; // error
  }
  music.play();
  StartScreen();
  music.stop();

    Player p;
    vector<Enemy> enemies;
    for (int i = 0; i < 20; i++)
    {
        enemies.push_back(Enemy(i * 30 + 300, 0));
    }

    int time = 0;
    bool left = false;
    while (display.window.isOpen())
    {
        Event e;
        // Checks for any input from user and it send it to event handler
        while (display.window.pollEvent(e)||check)
        {
            if (e.type == Event::KeyPressed)
            {
                if (e.key.code == Keyboard::Space)
                {
                  p.Shoot();
                  if (!music.openFromFile("Laser.ogg"))
                  {
                      return -1; // error
                  }
                  music.play();
                }
                else if (e.key.code == Keyboard::Escape)
                {
                    display.window.close();
                    check = 0;
                }
                else
                {
                    p.Movement(e);
                }
            }
            if (e.type == Event::Closed)
            {
                display.window.close();
                check = 0;
            }
            if (p.gameOver())
            {
                display.window.close();
                check = 0;
            }
            if (enemies.size() == 0)
            {
                display.window.close();
                check = 0;
            }

            int selection = rand() % enemies.size(); //Randomly selects an enemy ship
            int check = 0;
            int previous = 0;
            for (int i = 0; i < enemies.size(); i++) //Checks if any ship has started moving
            {
                if (enemies[i].getShape().getPosition().y == 0)
                {
                    check++;
                }
                else
                {
                    previous = i;
                }
            }
            if (check == enemies.size()) //If no enemy has moved, the randomly selected one moves
            {
                enemies[selection].move();
            }
            else //Otherwise the one that has moved continues moving
            {
                    enemies[previous].move();
            }
            if (time == 0)
            {
                left = true;
            }
            else
            {
                time--;
            }
            for (int i = 0; i < enemies.size(); i++)
            {
                enemies[i].backAndForth(left);
            }
            if (enemies[0].getShape().getPosition().x < 100 && time == 0)
            {
                time = 200;
                left = false;
            }
            //Clears the window
            display.window.clear();

            for (int i = 0; i < p.getProjectiles().size(); i++) //Updates the projectiles with there new position
            {
                p.updateProjectiles(i, enemies);
            }

            display.window.draw(p.getShape()); //Draws the player on the screen

            for (int i = 0; i < p.getProjectiles().size(); i++) //Draws the player's projectiles on the screen
            {
                display.window.draw(p.getProjectiles()[i]);
            }

            for (int i = 0; i < enemies.size(); i++) //Draws the enemies on the screen
            {
                display.window.draw(enemies[i].getShape());
            }

            //sf::CircleShape shape(50);
            //shape.setFillColor(sf::Color(100, 250, 50));
            //window.draw(shape);


            //Displays the new frame
            display.window.display();
            for (int i = 0; i < enemies.size(); i++)
            {
                p.checkCollison(enemies[i]);
            }
        }


        std::cout << "Hello World!\n";

        return 0;
    }
}
