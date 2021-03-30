#include <iostream>
#include "Player.h"
#include "Enemy.h"
using namespace sf;
using namespace std;

int main()
{
    int check = 1;
    sf::Music music;
    if (!music.openFromFile("GalagaTheme.ogg"))
        return -1; // error
    music.play();


    Player p;
    vector<Enemy> enemies;
    for (int i = 0; i < 20; i++)
    {
        enemies.push_back(Enemy(i * 30 + 300));
    }

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

            int selection = rand() % 20; //Randomly selects an enemy ship
            int check = 0;
            int previous;
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

            //Clears the window
            display.window.clear();

            for (int i = 0; i < p.getProjectiles().size(); i++)
            {
                p.updateProjectiles(i);
            }

            display.window.draw(p.getShape());
            
            for (int i = 0; i < p.getProjectiles().size(); i++)
            {
                display.window.draw(p.getProjectiles()[i]);
            }

            for (int i = 0; i < enemies.size(); i++)
            {
                display.window.draw(enemies[i].getShape());
            }
            //sf::CircleShape shape(50);
            //shape.setFillColor(sf::Color(100, 250, 50));
            //window.draw(shape);


            //Displays the new frame
            display.window.display();
        }   


        std::cout << "Hello World!\n";

        return 0;
    }
}
    