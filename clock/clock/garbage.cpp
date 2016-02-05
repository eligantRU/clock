#include "stdafx.h"
#include "sheet.h"

time_t getSystemTime(void)
{
	return std::time(NULL);
}

void mainLoop(sf::RenderWindow & window)
{
	Clock clock;
	clock.initialize();

	while (window.isOpen())
	{
		clock.frameFunc(window);
		clock.update();
		clock.render(window);
		checkClick(window);
	}
}

void checkClick(sf::RenderWindow & window)
{
	sf::Event event;

	if ((window.pollEvent(event)) && (event.type == sf::Event::Closed))
	{
		window.close();
	}
}

void enterTimeLoop(void)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;

	sf::RenderWindow window(sf::VideoMode(400, 400), "Clock", sf::Style::Close, settings);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	
	mainLoop(window);
}
