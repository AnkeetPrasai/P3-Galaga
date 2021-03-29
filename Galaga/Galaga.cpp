#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include "Player.h"

using namespace sf;

int main()
{
    int check = 1;
    sf::Music music;
    if (!music.openFromFile("GalagaTheme.ogg"))
        return -1; // error
    music.play();


    Player p;
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
    