#include "stdafx.h"
#include "sheet.h"
#include "clock.hpp"

// TODO: new file with "garbage"
time_t getSystemTime(void)
{
	return std::time(NULL);
}

void mainLoop(sf::RenderWindow & window, Clock & clock)
{
	sf::Event event;

	while (window.isOpen())
	{
		clock.frameFunc(window);
		if ((window.pollEvent(event)) && (event.type == sf::Event::Closed)) // TODO: new function
		{
			window.close();
		}
	}
}

void enterTimeLoop(void)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;

	sf::RenderWindow window(sf::VideoMode(400, 400), "Clock", sf::Style::Close, settings);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	Clock clock;
	clock.preparation();
	
	mainLoop(window, clock);
}

int main(void)
{
	enterTimeLoop();
	return 0;
}
