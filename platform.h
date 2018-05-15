#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#define MAX_PLATFORMS 10

class platform
{
public:
	platform();
	~platform();


	void update(float dt);
	void draw(RenderWindow &window);

private:
	RectangleShape platRect;
	Vector2f platPosition [MAX_PLATFORMS];
	Vector2f platSize;
	float platRotation;
};

