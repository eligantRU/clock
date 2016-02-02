#pragma once

#include <SFML/Graphics.hpp>

struct Clock
{
public:
	void setSysTime(time_t sysTime);
	void frameFunc(sf::RenderWindow & window);
	void setClockCircle(sf::CircleShape & clockCircle);
	void initialize(void);
private:
	void setLocTime();
	int getHour();
	int getMin();
	int getSec();
	void render(sf::RenderWindow & window);
	void update();
	void setFont(void);

	time_t sysTime;
	struct tm locTime;
	sf::CircleShape clockCircle;
	sf::CircleShape centerCircle;
	sf::RectangleShape secArrow;
	sf::RectangleShape minArrow;
	sf::RectangleShape hourArrow;
	sf::CircleShape circlesSec[60];
	sf::CircleShape circlesHour[12];
	sf::Text numHour[12];
	sf::Font font;
};