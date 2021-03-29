#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"

using namespace sf;
extern Music music;

#ifndef Display_H
#define Display_H

class Display
{
	public:
		Display();
		~Display();
		RenderWindow window;

};
#endif