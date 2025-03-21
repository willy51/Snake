#include "Snake.h"

Snake::Snake() : pos_X(3*SPRITE_SIZE/2), pos_Y(3*SPRITE_SIZE/2), speed(SPRITE_SIZE), size(3), moveDelay(0.2f), sprite(nullptr),texture(nullptr) {
	texture = new Texture();
	if (!texture->loadFromFile("res/Sprite/snake.png")) {
		cout << "Sprite not found" << endl;
		delete texture;
		texture = nullptr;
		return;
	}

	sprite = new Sprite(*texture);

}

void Snake::up() {
    static Clock clock;
    if (clock.getElapsedTime().asSeconds() >= moveDelay) {
        if (pos_Y >= 0) {
            pos_Y -= speed;
        }
        else {
            pos_Y = WIN_HEIGHT + SPRITE_SIZE /2;
        }
        clock.restart(); 
    }
}

void Snake::down() {
    static Clock clock;
    if (clock.getElapsedTime().asSeconds() >= moveDelay) {
        if (pos_Y <= WIN_HEIGHT) {
            pos_Y += speed;
        }
        else {
            pos_Y = SPRITE_SIZE / 2;
        }
        clock.restart(); 
    }
}

void Snake::left() {
    static Clock clock;
    if (clock.getElapsedTime().asSeconds() >= moveDelay) {
        if (pos_X >= 0) {
            pos_X -= speed;
        }
        else {
            pos_X = WIN_WIDTH + SPRITE_SIZE / 2;
        }
        clock.restart(); 
    }
}

void Snake::right() {
    static Clock clock;
    if (clock.getElapsedTime().asSeconds() >= moveDelay) {
        if (pos_X <= WIN_WIDTH) {
            pos_X += speed;
        }
        else {
            pos_X = SPRITE_SIZE / 2;
        }
        clock.restart(); 
    }
}


float Snake::getPosX() {
	return pos_X;
}

float Snake::getPosY() {
	return pos_Y;
}

int Snake::getSize() const {
	return size;
}

const Sprite& Snake::getSprite() const {
    return *sprite; 
}


const Texture& Snake::getTexture() const {
	return *texture;
}

void Snake::addSize() {
	size++;
}

void Snake::removeMoveDelay()
{
    moveDelay -= 0.002;
}



