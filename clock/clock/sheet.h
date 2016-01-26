#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>

struct Clock
{
public:
	void setSysTime(time_t sysTime);
	void frameFunc(sf::RenderWindow & window);
	void setClockCircle(sf::CircleShape & clockCircle);
	void preparation(void);
private:
	void setLocTime();
	int getHour();
	int getMin();
	int getSec();
	void render(sf::RenderWindow & window);

	time_t sysTime;
	struct tm locTime;
	sf::CircleShape clockCircle;
};

time_t getSystemTime(void);

void enterTimeLoop(void);

void mainLoop(sf::Window & window, Clock & clock);