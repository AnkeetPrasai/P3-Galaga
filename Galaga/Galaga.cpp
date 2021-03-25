#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1280, 720), "GALAGA", Style::Default);


    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();

        }

        window.clear();

        window.display();
    }
    std::cout << "Hello World!\n";

    return 0;
}
