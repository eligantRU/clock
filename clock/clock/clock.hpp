#include "stdafx.h"
#include "sheet.h"

void Clock::setSysTime(time_t sysTime)
{
	Clock::sysTime = sysTime;
}

void Clock::frameFunc(sf::RenderWindow & window)
{
	// TODO: check events(e.x. window.close)
	// TODO: no debug console
	Clock::setSysTime(getSystemTime());
	Clock::setLocTime();
	Clock::update();
	Clock::render(window);
}

void Clock::update()
{
	Clock::secArrow.setRotation(float(Clock::getSec() * 6 - 90)); // 360 (rad) / 60 (ones) = 6
	Clock::minArrow.setRotation(float(Clock::getMin() * 6 - 90)); // TODO: -90 & -75 -- added constants or fix shapes generation
	Clock::hourArrow.setRotation(float(Clock::getHour() * 30 - 75)); // 360 (rad) / 12 (ones) = 30
}

void Clock::preparation(void)
{
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

	// TODO: new function
	window.draw(clockCircle);
	window.draw(secArrow);
	window.draw(minArrow);
	window.draw(hourArrow);
	window.draw(centerCircle);

	window.display();
}