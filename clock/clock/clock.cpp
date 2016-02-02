#include "stdafx.h"
#include "sheet.h"
#include <windows.h> 


void Clock::setSysTime(time_t sysTime)
{
	Clock::sysTime = sysTime;
}

void Clock::frameFunc(sf::RenderWindow & window)
{
	Clock::setSysTime(getSystemTime());
	Clock::setLocTime();
	Clock::update();
	Clock::render(window);
}

void Clock::update()
{
	Clock::secArrow.setRotation(float(Clock::getSec() * 6 - 90)); // 360 (rad) / 60 (ones) = 6
	Clock::minArrow.setRotation(float(Clock::getMin() * 6 - 90)); // TODO: -90 & -75 -- added constants
	Clock::hourArrow.setRotation(float(Clock::getHour() * 30) + float(Clock::getMin() / 2) - 90); // Similarly
}

void Clock::setFont(void)
{
	if (!Clock::font.loadFromFile("arial.ttf"))
	{
		MessageBoxA(NULL, "'arial.ttf' not founded", "Error", MB_ICONERROR | MB_OK);
		_exit(-1);
	}
}

void Clock::initialize(void)
{
	Clock::setFont();

	Clock::setClockCircle(clockCircle);

	// TODO: new functions
	Clock::centerCircle.setPosition(190.f, 190.f);
	Clock::centerCircle.setRadius(10);
	Clock::centerCircle.setFillColor(sf::Color(0, 0, 0));
	Clock::centerCircle.setPointCount(100);

	Clock::secArrow.setSize(sf::Vector2f(200, 2));
	Clock::secArrow.setFillColor(sf::Color(127, 127, 127));
	Clock::secArrow.setPosition(200.f, 200.f);
	Clock::secArrow.setRotation(-90);

	Clock::minArrow.setSize(sf::Vector2f(150, 3));
	Clock::minArrow.setFillColor(sf::Color(63, 63, 63));
	Clock::minArrow.setPosition(200.f, 200.f);
	Clock::minArrow.setRotation(-90);

	Clock::hourArrow.setSize(sf::Vector2f(75, 3));
	Clock::hourArrow.setFillColor(sf::Color(31, 31, 31));
	Clock::hourArrow.setPosition(200.f, 200.f);
	Clock::hourArrow.setRotation(-90);

	for (int i = 0; i < 60; ++i) // TODO: new function
	{
		Clock::circlesSec[i].setRadius(2);
		Clock::circlesSec[i].setFillColor(sf::Color(50, 50, 50));
		Clock::circlesSec[i].setPointCount(100);
		double PI = 3.14159265358979;
		double x = 200.f - 2.f + 180 * cos(6 * i * PI/180); // 6 = 360 / 60
		double y = 200.f - 2.f + 180 * sin(6 * i * PI/180); // 200 -- R(big), 180 -- R(s), 4 -- R(circlesSec)
		Clock::circlesSec[i].setPosition(float(x), float(y));
	}

	for (int i = 0; i < 12; ++i) // TODO: new function
	{
		Clock::circlesHour[i].setRadius(4);
		Clock::circlesHour[i].setFillColor(sf::Color(50, 50, 50));
		Clock::circlesHour[i].setPointCount(100);
		double PI = 3.14159265358979;
		double x = 200.f - 4.f + 180 * cos(30 * i * PI / 180); // 30 = 360 / 12
		double y = 200.f - 4.f + 180 * sin(30 * i * PI / 180); // 200 -- R(big), 180 -- R(s), 4 -- R(circlesHour)
		Clock::circlesHour[i].setPosition(float(x), float(y));
	}

	for (int i = 0; i < 12; ++i) // TODO: new function
	{
		numHour[i].setFont(Clock::font);
		numHour[i].setCharacterSize(20);
		numHour[i].setString(std::to_string(i + 1));
		numHour[i].setStyle(sf::Text::Bold);
		numHour[i].setColor(sf::Color(0, 0, 0));
		double PI = 3.14159265358979;
		double x = 200.f - 6.f - 155 * sin(30 * i * PI / 180 + 7*PI/6); // 30 = 360 / 12
		if (i > 9)
		{
			x -= 6.f;
		}
		double y = 200.f - 12.f + 155 * cos(30 * i * PI / 180 + 7*PI/6);
		numHour[i].setPosition(float(x), float(y));
	}
}

void Clock::setClockCircle(sf::CircleShape & clockCircle)
{
	Clock::clockCircle.setPosition(0.f, 0.f);
	Clock::clockCircle.setRadius(200);
	Clock::clockCircle.setFillColor(sf::Color(255, 255, 255));
	Clock::clockCircle.setPointCount(100);
}

void Clock::setLocTime()
{
	localtime_s(&locTime, &sysTime);
}

int Clock::getHour()
{
	return (Clock::locTime.tm_hour % 12);
}

int Clock::getMin()
{
	return Clock::locTime.tm_min;
}

int Clock::getSec()
{
	return Clock::locTime.tm_sec;
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
	window.display();
}