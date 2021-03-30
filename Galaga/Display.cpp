#include "Display.h"
sf::Music music;

Display::Display():window(VideoMode(1280, 720), "GALAGA", Style::Default)
{
	window.setFramerateLimit(30);
}

Display::~Display()
{

}
