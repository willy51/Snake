#include "Game.h"


const float SPRITE_CHANGE_INTERVAL = 0.15f;

TextFont textFont;
Font font = textFont.getFont();
Text text(font);
Input input;



Apple apple;
Sprite appleSprite = apple.getSprite();
Texture appleTexture = apple.getTexture();

Vector2i anim(0, 0);
bool updateFPS = true;
bool startMove = false;
int direction = -1;

deque<Segment> pos;

Game::Game(RenderWindow& window, Snake& snake) : window(window), snake(snake), sprite(snake.getSprite()), texture(snake.getTexture()) {
}

void Game::start() {
    textFont.SetText(text, "Score : " + to_string(snake.getSize() - 3));

    Clock animationClock, clock;
    float timeSinceLastChange = 0.0f;

    sprite.setOrigin({ SPRITE_SIZE / 2, SPRITE_SIZE / 2 });
    float lastPosX = sprite.getPosition().x, lastPosY = sprite.getPosition().y;

    appleSprite.setOrigin({ APPLE_SPRITE_SIZE / 2, APPLE_SPRITE_SIZE / 2 });
    appleSprite.setPosition({ apple.getPosX(), apple.getPosY() });

    pos.push_front(Segment{ -100, 0, static_cast<float>(direction) });
    pos.push_front(Segment{ -100, 0, static_cast<float>(direction) });
    pos.push_front(Segment{ -100, 0, static_cast<float>(direction) });

    while (window.isOpen()) {
        while (const optional<sf::Event> event = window.pollEvent()) {
            input.InputHandler(event, window);
        }

        float deltaTime = animationClock.restart().asSeconds();
        timeSinceLastChange += deltaTime;


        setAnimation(timeSinceLastChange);
        manageInput();


        if (lastPosX != sprite.getPosition().x || lastPosY != sprite.getPosition().y) {
            float newX = lastPosX;
            float newY = lastPosY;

            switch (direction) {
            case 0: // UP
                newY -= SPRITE_SIZE;
                break;
            case 1: // RIGHT
                newX += SPRITE_SIZE;
                break;
            case 2: // DOWN
                newY += SPRITE_SIZE;
                break;
            case 3: // LEFT
                newX -= SPRITE_SIZE;
                break;
            default:
                break;
            }


            pos.push_front(Segment{ newX, newY, static_cast<float>(direction) });
            lastPosX = sprite.getPosition().x;
            lastPosY = sprite.getPosition().y;
        }


        if (sprite.getPosition().x > appleSprite.getPosition().x - APPLE_SPRITE_SIZE / 2 &&
            sprite.getPosition().x < appleSprite.getPosition().x + APPLE_SPRITE_SIZE / 2 &&
            sprite.getPosition().y > appleSprite.getPosition().y - APPLE_SPRITE_SIZE / 2 &&
            sprite.getPosition().y < appleSprite.getPosition().y + APPLE_SPRITE_SIZE / 2) {
            snake.addSize();
            textFont.SetText(text, "Score : " + to_string(snake.getSize() - 3));
            snake.removeMoveDelay();
            apple.setNewPos();
            bool isOnSnake;
            do {
                apple.setNewPos();
                isOnSnake = false;
                for (size_t i = 1; i < snake.getSize(); i++) {
                    if (apple.getPosX() == pos[i].x && apple.getPosY() == pos[i].y) {
                        isOnSnake = true;
                        break;
                    }
                }
            } while (isOnSnake);
            appleSprite.setPosition({ apple.getPosX(), apple.getPosY() });
        }

        if (startMove) {
            for (size_t i = 1; i < snake.getSize() + 1; i++) {

                if (sprite.getPosition().x < pos[i].x + SPRITE_SIZE / 2 && sprite.getPosition().x > pos[i].x - SPRITE_SIZE / 2 &&
                    sprite.getPosition().y < pos[i].y + SPRITE_SIZE / 2 && sprite.getPosition().y > pos[i].y - SPRITE_SIZE / 2) {
                    Menu menu(window,snake.getSize() - 3);
                    menu.menuWindow();
                }
            }
        }
        Color color(49, 22, 45);
        window.clear(color);
        window.draw(text);
        window.draw(sprite);
        window.draw(appleSprite);

        drawSnake();

        window.display();
    }

}

void Game::drawSnake() {
    for (size_t i = 1; i < snake.getSize() + 1; i++) {
        Sprite body = snake.getSprite();
        body.setTextureRect(IntRect({ 2 * SPRITE_SIZE, 2 * SPRITE_SIZE }, { SPRITE_SIZE, SPRITE_SIZE }));
        body.setOrigin({ SPRITE_SIZE / 2, SPRITE_SIZE / 2 });
        body.setPosition({ pos[i].x, pos[i].y });

        int currentDir = pos[i].orientation;
        int prevDir = pos[i - 1].orientation;

        if (currentDir == 0) { // UP
            if (prevDir == 1) body.setTextureRect({ { 1 * SPRITE_SIZE, 0 }, { SPRITE_SIZE, SPRITE_SIZE } });
            if (prevDir == 3) body.setTextureRect({ { 2 * SPRITE_SIZE, 0 }, { SPRITE_SIZE, SPRITE_SIZE } });
            if (i == snake.getSize()) body.setTextureRect({ { 1 * SPRITE_SIZE, 2 * SPRITE_SIZE }, { SPRITE_SIZE, SPRITE_SIZE } });
            body.setRotation(degrees(0));
        }

        else if (currentDir == 1) { // RIGHT
            if (prevDir == 0) body.setTextureRect({ { 2 * SPRITE_SIZE, 0 }, { SPRITE_SIZE, SPRITE_SIZE } });
            if (prevDir == 2) body.setTextureRect({ { 1 * SPRITE_SIZE, 0 }, { SPRITE_SIZE, SPRITE_SIZE } });
            if (i == snake.getSize()) body.setTextureRect({ { 1 * SPRITE_SIZE, 2 * SPRITE_SIZE }, { SPRITE_SIZE, SPRITE_SIZE } });
            body.setRotation(degrees(90));
        }
        else if (currentDir == 2) { // DOWN
            if (prevDir == 1) body.setTextureRect({ { 2 * SPRITE_SIZE, 0 }, { SPRITE_SIZE, SPRITE_SIZE } });
            if (prevDir == 3) body.setTextureRect({ { 1 * SPRITE_SIZE, 0 }, { SPRITE_SIZE, SPRITE_SIZE } });
            if (i == snake.getSize()) body.setTextureRect({ { 1 * SPRITE_SIZE, 2 * SPRITE_SIZE }, { SPRITE_SIZE, SPRITE_SIZE } });
            body.setRotation(degrees(180));
        }
        else if (currentDir == 3) { // LEFT
            if (prevDir == 0) body.setTextureRect({ { 1 * SPRITE_SIZE, 0 }, { SPRITE_SIZE, SPRITE_SIZE } });
            if (prevDir == 2) body.setTextureRect({ { 2 * SPRITE_SIZE, 0 }, { SPRITE_SIZE, SPRITE_SIZE } });
            if (i == snake.getSize()) body.setTextureRect({ { 1 * SPRITE_SIZE, 2 * SPRITE_SIZE }, { SPRITE_SIZE, SPRITE_SIZE } });
            body.setRotation(degrees(-90));
        }

        window.draw(body);
    }
}

void Game::setAnimation(float& timeSinceLastChange) {
    if (timeSinceLastChange >= SPRITE_CHANGE_INTERVAL) {
        anim.y = (anim.y + 1) % (texture.getSize().y / SPRITE_SIZE);
        timeSinceLastChange = 0.0f;
    }

    sprite.setTextureRect(IntRect({ anim.x * SPRITE_SIZE, anim.y * SPRITE_SIZE }, { SPRITE_SIZE, SPRITE_SIZE }));
    sprite.setPosition({ snake.getPosX(), snake.getPosY() });
}

void Game::manageInput() {
    if (input.getButton().down) {
        direction = 2;
        snake.down();
        sprite.setRotation(degrees(0));
        startMove = true;
    }
    if (input.getButton().up) {
        direction = 0;
        snake.up();
        sprite.setRotation(degrees(180));
        startMove = true;
    }
    if (input.getButton().left) {
        direction = 3;
        snake.left();
        sprite.setRotation(degrees(90));
        startMove = true;
    }
    if (input.getButton().right) {
        direction = 1;
        snake.right();
        sprite.setRotation(degrees(-90));
        startMove = true;
    }
}
