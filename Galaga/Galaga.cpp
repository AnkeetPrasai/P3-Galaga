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
    if (!music.openFromFile("GalagaTheme.ogg"))
        return -1; // error
    music.play();


    Player p;
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
                    p.Shoot(e);
                }
                else if (e.key.code == Keyboard::Escape)
                {
                    display.window.close();
                }
                else
                {
                    p.Movement(e);
                }
            }
            if (e.type == Event::Closed)
            {

                display.window.close();
            }

            //Clears the window
            display.window.clear();

            display.window.draw(p.getShape());
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
    