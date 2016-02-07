#pragma once

#include <SFML/Graphics.hpp>
#include "clock.h"
#include <ctime>
#include <string>

time_t getSystemTime(void);

void enterTimeLoop(void);

void checkEvents(sf::RenderWindow & window);

void mainLoop(sf::Window & window);