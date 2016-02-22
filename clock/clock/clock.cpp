#include "stdafx.h"
#include "sheet.h"	

void Clock::setTime(time_t sysTime)
{
	localtime_s(&locTime, &sysTime);
}

void Clock::update(void)
{
	secArrow.setRotation(float(getSec() * 6 - 90)); // 360 (rad) / 60 (ones) = 6
	minArrow.setRotation(float(getMin() * 6 - 90)); // -90 & -75 -- added constants
	hourArrow.setRotation(float(getHour() * 30) + float( getMin() / 2) - 90); // Similarly
}

void Clock::setupFont(void)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		MessageBoxA(NULL, "'arial.ttf' not founded", "Error", MB_ICONERROR | MB_OK);
		_exit(-1);
	}
}

void Clock::fixPosition(const std::string & str, sf::Vector2f & position)
{
	if (str.length() > 1)
	{
		position.x -= 6.f;
	}
}

void Clock::setCirclesSecCoordinates(sf::Vector2f & coordinates, int & sec)
{
	coordinates.x = 200.f - 2.f + 180.f * cos(degree2Radaian(6 * sec)); // 6 = 360 / 60
	coordinates.y = 200.f - 2.f + 180.f * sin(degree2Radaian(6 * sec)); // 200 -- R(big), 180 -- R(s), 4 -- R(circlesSec)
}

void Clock::setCirclesHourCoordinates(sf::Vector2f & coordinates, int & hour)
{
	coordinates.x = 200.f - 4.f + 180.f * cos(degree2Radaian(30 * hour)); // 30 = 360 / 12
	coordinates.y = 200.f - 4.f + 180.f * sin(degree2Radaian(30 * hour)); // 200 -- R(big), 180 -- R(s), 4 -- R(circlesHour)
}

void Clock::setNumHourCoordinates(sf::Vector2f & coordinates, int & numHour)
{
	coordinates.x = 200.f - 6.f - 155.f * sin(degree2Radaian(30 * numHour + 210)); // 30 = 360 / 12
	coordinates.y = 200.f - 12.f + 155.f * cos(degree2Radaian(30 * numHour + 210));
}

void Clock::setCenterCircle(sf::CircleShape & centerCircle)
{
	centerCircle.setPosition(190.f, 190.f);
	centerCircle.setRadius(10);
	centerCircle.setFillColor(sf::Color(0, 0, 0));
	centerCircle.setPointCount(100);
}

void Clock::setSecArrow(sf::RectangleShape & secArrow)
{
	secArrow.setSize(sf::Vector2f(200, 2));
	secArrow.setFillColor(sf::Color(127, 127, 127));
	secArrow.setPosition(200.f, 200.f);
	secArrow.setRotation(-90);
}

void Clock::setMinArrow(sf::RectangleShape & minArrow)
{
	minArrow.setSize(sf::Vector2f(150, 3));
	minArrow.setFillColor(sf::Color(63, 63, 63));
	minArrow.setPosition(200.f, 200.f);
	minArrow.setRotation(-90);
}

void Clock::setHourArrow(sf::RectangleShape & hourArrow)
{
	hourArrow.setSize(sf::Vector2f(75, 3));
	hourArrow.setFillColor(sf::Color(31, 31, 31));
	hourArrow.setPosition(200.f, 200.f);
	hourArrow.setRotation(-90);
}

void Clock::setCirclesSec(sf::CircleShape * circlesSec)
{
	for (int i = 0; i < 60; ++i)
	{
		circlesSec[i].setRadius(2);
		circlesSec[i].setFillColor(sf::Color(50, 50, 50));
		circlesSec[i].setPointCount(100);

		sf::Vector2f circleSec(0.f, 0.f);

		setCirclesSecCoordinates(circleSec, i);
		circlesSec[i].setPosition(circleSec);
	}
}

void Clock::setCirclesHour(sf::CircleShape * circlesHour)
{
	for (int i = 0; i < 12; ++i)
	{
		circlesHour[i].setRadius(4);
		circlesHour[i].setFillColor(sf::Color(50, 50, 50));
		circlesHour[i].setPointCount(100);

		sf::Vector2f circleHourPosition(0.f, 0.f);

		setCirclesHourCoordinates(circleHourPosition, i);
		circlesHour[i].setPosition(circleHourPosition);
	}
}

void Clock::setNumHour(sf::Text * numHour)
{
	for (int i = 0; i < 12; ++i)
	{
		numHour[i].setFont(font);
		numHour[i].setCharacterSize(20);
		numHour[i].setString(std::to_string(i + 1));
		numHour[i].setStyle(sf::Text::Bold);
		numHour[i].setColor(sf::Color(0, 0, 0));

		sf::Vector2f numHourPosition(0.f, 0.f);

		setNumHourCoordinates(numHourPosition, i);
		fixPosition(std::to_string(i + 1), numHourPosition);
		numHour[i].setPosition(numHourPosition);
	}
}

void Clock::initialize(void)
{
	setupFont();

	setClockCircle(clockCircle);
	setCenterCircle(centerCircle);
	setSecArrow(secArrow);
	setMinArrow(minArrow);
	setHourArrow(hourArrow);
	setCirclesSec(circlesSec);
	setCirclesHour(circlesHour);
	setNumHour(numHour);
}

void Clock::setClockCircle(sf::CircleShape & clockCircle)
{
	clockCircle.setPosition(0.f, 0.f);
	clockCircle.setRadius(200);
	clockCircle.setFillColor(sf::Color(255, 255, 255));
	clockCircle.setPointCount(100);
}

int Clock::getHour(void)
{
	return (locTime.tm_hour % 12);
}

int Clock::getMin(void)
{
	return locTime.tm_min;
}

int Clock::getSec(void)
{
	return locTime.tm_sec;
}

void Clock::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(100, 100, 100));

	window.draw(clockCircle);
	window.draw(hourArrow);
	window.draw(minArrow);;
	window.draw(secArrow);
	window.draw(centerCircle);
	for (int i = 0; i < 60; ++i)
	{
		window.draw(circlesSec[i]);
	}
	for (int i = 0; i < 12; ++i)
	{
		window.draw(circlesHour[i]);
	}
	for (int i = 0; i < 12; ++i)
	{
		window.draw(numHour[i]);
	}
}