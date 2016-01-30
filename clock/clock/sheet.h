#pragma once

#include <SFML/Graphics.hpp>
#include "clock.h"
#include <ctime>
#include <cmath>

time_t getSystemTime(void);

void enterTimeLoop(void);

void checkClick(sf::RenderWindow & window);

void mainLoop(sf::Window & window);