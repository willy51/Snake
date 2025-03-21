#ifndef DEF_GAME
#define DEF_GAME

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <deque>
#include <iostream>

#include "Global.h"
#include "TextFont.h"
#include "Input.h"
#include "Apple.h"
#include "Snake.h"
#include "Menu.h"

using namespace sf;
using namespace std;

struct Segment {
    float x, y, orientation;
};

class Game {
public:
    Game(RenderWindow& window, Snake& snake);
    void start();

private:
    RenderWindow& window;
    void manageInput();
    void setAnimation(float& timeSinceLastChange);
    void drawSnake();
    Snake snake;
    Sprite sprite;
    Texture texture;


};


#endif // !SS_UI_MAIN_MENU_H_