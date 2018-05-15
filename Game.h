#pragma once
#include <SFML/Graphics.hpp>
#include "platform.h"

using namespace sf;

class Game
{
public:
	
	Game(RenderWindow &window, int width, int height);
	~Game();

	platform plat;
	void run(RenderWindow &window);
	Font mFont;
	Text mText;
	int gameState;
	int speed;

	bool isColliding;

	bool isCollidingUp;

private:
	void processEvents(RenderWindow &window);
	void update(Time elapsedTime);
	void render(RenderWindow &window);

	static const Time TimePerFrame;
};