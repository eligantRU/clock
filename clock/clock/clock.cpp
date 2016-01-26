#include "stdafx.h"
#include "sheet.h"
#include "clock.hpp"

time_t getSystemTime(void)
{
	return std::time(NULL);
}

void mainLoop(sf::RenderWindow & window, Clock & clock)
{
	while (window.isOpen())
	{
		clock.frameFunc(window);
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
	clock.setSysTime(getSystemTime()); // TODO: -> mainLoop

	mainLoop(window, clock);
}

int main()
{
	enterTimeLoop();
	return 0;
}
