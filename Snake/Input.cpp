#include "Input.h"

Input::Input() : lastButton(-1){
    button.down = button.left = button.right = button.up = false;
}

Input::Button Input::getButton() {
    return button;
}
void Input::InputHandler(optional<Event> event, RenderWindow& window) {
    if (event->is<Event::Closed>()){
        window.close();
    }
    if (event->is<Event::KeyPressed>()) {
        auto key = event->getIf<Event::KeyPressed>()->code;
        if (key == Keyboard::Key::Up && lastButton != 2) {
            button.up = true;
            button.down = button.left = button.right = false;
            lastButton = 0;
        }
        if (key == Keyboard::Key::Left && lastButton != 3) {
            button.left = true;
            button.down = button.right = button.up = false;
            lastButton = 1;
        }
        if (key == Keyboard::Key::Down && lastButton != 0) {
            button.down = true;
            button.left = button.right = button.up = false;
            lastButton = 2;
        }
        if (key == Keyboard::Key::Right && lastButton != 1) {
            button.right = true;
            button.down = button.left = button.up = false;
            lastButton = 3;
        }
    }

}