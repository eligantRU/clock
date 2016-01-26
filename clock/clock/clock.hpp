#include "stdafx.h"
#include "sheet.h"

void Clock::setSysTime(time_t sysTime)
{
	Clock::sysTime = sysTime;
}

void Clock::frameFunc(sf::RenderWindow & window)
{
	Clock::setLocTime();
	Clock::render(window);
	//update();
}

void Clock::preparation(void)
{
	Clock::setClockCircle(clockCircle);
}

void Clock::setClockCircle(sf::CircleShape & clockCircle)
{
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
	return Clock::locTime.tm_hour;
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
	window.clear(sf::Color(0, 0, 0));
	window.draw(clockCircle);
	window.display();
}