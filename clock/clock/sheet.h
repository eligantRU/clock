#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>

// TODO: new file(clock.h)
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
	void update();

	time_t sysTime;
	struct tm locTime;
	sf::CircleShape clockCircle;
	sf::CircleShape centerCircle;
	sf::RectangleShape secArrow;
	sf::RectangleShape minArrow;
	sf::RectangleShape hourArrow;
};

time_t getSystemTime(void);

void enterTimeLoop(void);

void mainLoop(sf::Window & window, Clock & clock);