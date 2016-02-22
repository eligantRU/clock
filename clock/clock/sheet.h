#pragma once

#include <SFML/Graphics.hpp>
#include "clock.h"

time_t getSystemTime(void);

void enterTimeLoop(void);

void checkEvents(sf::RenderWindow & window);

void mainLoop(sf::Window & window);

float degree2Radaian(int degree);