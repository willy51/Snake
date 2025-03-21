#pragma once

#ifndef DEF_MENU
#define DEF_MENU

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Game.h"

using namespace sf;
using namespace std;

class Menu
{
public:
	Menu(RenderWindow& window, int score);
	void menuWindow();
	void launchGame();

private:
	RenderWindow& window;
	int lastScore;
};




#endif // !DEF_MENU
