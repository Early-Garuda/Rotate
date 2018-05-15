#include "platform.h"



platform::platform()
{
	platRect.setFillColor(Color::Blue);
	for (int i = 0; i < MAX_PLATFORMS; i++)
	{
		platPosition[i] = Vector2f(1 + i * 100, 200);
		platRect.setPosition(platPosition[i]);
	}

	platSize = Vector2f(10, 200);
	platRect.setOrigin(5, 100);
	platRect.setSize(platSize);


}


platform::~platform()
{
}

void platform::update(float dt)
{	
	platRect.rotate(1);
}

void platform::draw(RenderWindow & window)
{
	for (int i = 0; i < MAX_PLATFORMS; i++)
	{
		platPosition[i] = Vector2f(1 + i * 50, 200);
		platRect.setPosition(platPosition[i]);
		window.draw(platRect);
	}

}
