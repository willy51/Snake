#pragma once
#ifndef DEF_APPLE
#define DEF_APPLE
#include "Global.h"
#include <cstdlib>

class Apple
{
public:
	Apple();
	Sprite getSprite() const;
	Texture getTexture() const;
	void setNewPos();
	float getPosX() const;
	float getPosY() const;
private:
	Texture* texture;
	Sprite* sprite;
	float pos_X;
	float pos_Y;
};

#endif // !DEF_APPLE


