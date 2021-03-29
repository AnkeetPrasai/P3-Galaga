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
	RenderWindow window(VideoMode(1280, 720), "GALAGA", Style::Default); //style chooses between windowed and fullscreen
					//Videomode you can set size
	window.setFramerateLimit(30);
	
	//Rate at which window updates

	//sf::Music music;
	//if (!music.openFromFile("Laser.ogg"))
		//return -1; // error
	//music.play();
	
	sf::Music music;
	if (!music.openFromFile("GalagaTheme.ogg"))
		return -1; // error
	music.play();


    Player p;
    while (window.isOpen()) {
        Event e;       

                    // Checks for any input from user and it send it to event handler
        while (window.pollEvent(e)) {
            if (e.type == Event::KeyPressed)
            {
                if (e.key.code == Keyboard::Space)
                {
                    p.Shoot(e);
                }
                else if (e.key.code == Keyboard::Escape)
                {
                    window.close();
                }
                else
                {
                    p.Movement(e);
                }
            }
            if (e.type == Event::Closed)
                window.close();

        }

        //Clears the window
        window.clear();

        window.draw(p.getShape());
		//sf::CircleShape shape(50);
		//shape.setFillColor(sf::Color(100, 250, 50));
		//window.draw(shape);
		

        //Displays the new frame
        window.display();
	
    }
    std::cout << "Hello World!\n";

    return 0;
}