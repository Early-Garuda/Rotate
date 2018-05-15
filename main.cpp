#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::Vector2f wSize(800, 800);
	sf::RenderWindow myWindow(sf::VideoMode(wSize.x, wSize.y), "EGGS Presents");;

	
	Game myGame(myWindow, wSize.x, wSize.y);
	myGame.run(myWindow);

	return 0;
}