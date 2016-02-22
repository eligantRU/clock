#pragma once

#include <SFML/Graphics.hpp>

struct Clock
{
public:
	void setTime(time_t sysTime);
	void initialize(void);
	void render(sf::RenderWindow & window);
	void update(void);
private:
	void setClockCircle(sf::CircleShape & clockCircle);
	void setCenterCircle(sf::CircleShape & centerCircle);
	void setSecArrow(sf::RectangleShape & secArrow);
	void setMinArrow(sf::RectangleShape & minArrow);
	void setHourArrow(sf::RectangleShape & hourArrow);
	void setCirclesSec(sf::CircleShape * circlesSec);
	void setCirclesHour(sf::CircleShape * circlesHour);
	void setNumHour(sf::Text * numHour);
	int getHour(void);
	int getMin(void);
	int getSec(void);
	void setupFont(void);
	void fixPosition(const std::string & str, sf::Vector2f & position);
	void setCirclesSecCoordinates(sf::Vector2f & coordinates, int & sec);
	void setCirclesHourCoordinates(sf::Vector2f & coordinates, int & hour);
	void setNumHourCoordinates(sf::Vector2f & coordinates, int & numHour);

	tm locTime;
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