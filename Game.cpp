#include "Game.h"

using namespace sf;

const Time Game::TimePerFrame = seconds(1.0f / 60.0f);
RectangleShape box(Vector2f(100.0f, 100.0f));
CircleShape ball(50);
//Constructor
Game::Game(RenderWindow & window, int width, int height)
{
	gameState = 1;
	if (!mFont.loadFromFile("CENTAUR.TTF"))
	{
		return;
	}
	mText.setFont(mFont);
	mText.setPosition(50.0f, 50.0f);
	mText.setCharacterSize(50);
	mText.setFillColor(Color::White);
	mText.setString("Space to play");

	box.setFillColor(Color::Black);
	box.setPosition(Vector2f(200, 200));

	ball.setFillColor(Color::White);
	ball.setPosition(Vector2f(300, 200));
	speed = 5;
}

void Game::run(RenderWindow &window)
{
	Clock clock;
	Time timeSinceLastUpdate = Time::Zero;//Reset Time

	while (window.isOpen())
	{
		Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents(window);
			update(TimePerFrame);
		}
		render(window);
	}
}


//Listen for window events
void Game::processEvents(RenderWindow &window)
{
	Event event;//Enable Closing Window
	while (window.pollEvent(event))
	{
		switch (event.type)		
		{
		case Event::Closed:
			window.close();
			break;
		default:
			break;
		}
	}
}
//Listen for input and move objects
void Game::update(Time elapsedTime)
{
	
	switch (gameState)
	{
	case 1:
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			gameState = 2;
		}
		break;
	case 2:
		

		if (ball.getGlobalBounds().intersects(box.getGlobalBounds()))
		{
			ball.setPosition(600, 200);
		}

		if (box.getGlobalBounds().intersects(plat.getRectangle().getGlobalBounds()))
		{
			isColliding = true;
		}
		else
		{
			isColliding = false;
		}



		if (Keyboard::isKeyPressed(Keyboard::A) && !isColliding)
		{
			box.move(-speed, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && !isColliding)
		{
			box.move(speed, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && isColliding)
		{
			box.move(0, 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::W) && !isColliding)
		{
			box.move(0, -speed);
		}
		if (Keyboard::isKeyPressed(Keyboard::S) && !isColliding)
		{
			box.move(0, speed);
		}
		
		

		if (Keyboard::isKeyPressed(Keyboard::U))
		{
			plat.update(elapsedTime.asSeconds());
		}

		break;
	
		//p1.update(0);
		
	default:
		/*
		{Speed.x = 0 Speed.y = 0}

		if D pressed {speed.x = 5}
		if A pressed {speed.x = -5}
		if W pressed {speed.y = 5}
		if S pressed {speed.y = -5}

		if speed.x < 0 -> going left
		if speed.x > 0 -> going right
		if speed.y < 0 -> going up
		if speed.y > 0 -> going down


		
		box.move(Speed.x, Speed.y);
		
		*/
		break;
	}
}
//Draw to screen
void Game::render(RenderWindow &window)
{
	switch (gameState)
	{
	case 1:
		window.clear(sf::Color::Green);
		window.draw(mText);
		break;
	case 2:
		window.clear(sf::Color::Green);
		window.draw(box);
		window.draw(ball);
		plat.draw(window);
		break;

	}
	window.display();
}

Game::~Game()
{
}

