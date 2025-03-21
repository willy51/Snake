#include "Apple.h"
#include <ctime>  

Apple::Apple() {
    static bool isRandInitialized = false;
    if (!isRandInitialized) {
        srand(time(NULL));
        isRandInitialized = true;
    }

    int step = SPRITE_SIZE / 2;

    pos_X = ((64 + rand() % (WIN_WIDTH - 128)) / step) * step;
    pos_Y = ((64 + rand() % (WIN_HEIGHT - 128)) / step) * step;

    texture = new Texture();
    if (!texture->loadFromFile("res/Sprite/apple.png")) {
        cout << "Sprite not found" << endl;
        delete texture;
        texture = nullptr;
        sprite = nullptr;
        return;
    }

    sprite = new Sprite(*texture);
}

Sprite Apple::getSprite() const {
    return *sprite;
}

Texture Apple::getTexture() const {
    return *texture;
}

void Apple::setNewPos()
{
    pos_X= 64 + rand() % (WIN_WIDTH - 64 + 1);
    pos_Y=64 + rand() % (WIN_HEIGHT - 64 + 1);
}

float Apple::getPosX() const {
    return pos_X;
}

float Apple::getPosY() const {
    return pos_Y;
}
