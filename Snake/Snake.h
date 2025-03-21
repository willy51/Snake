#pragma once
#ifndef DEF_SNAKE
#define DEF_SNAKE
#include "Global.h"

class Snake
{
public:
	Snake();
	void up();
	void down();
	void left();
	void right();
	float getPosX();
	float getPosY();
	int getSize() const;
	const Sprite& getSprite() const; 
	const Texture& getTexture() const;
	void addSize();
	void removeMoveDelay();

private:
	Texture* texture;
	Sprite* sprite;
	float pos_X;
	float pos_Y;
	float speed;
	int size;
	float moveDelay; 
};


#endif // !DEF_SNAKE

