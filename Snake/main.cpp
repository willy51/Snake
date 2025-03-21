#include "Menu.h"

int WinMain() {
    RenderWindow window(VideoMode({ WIN_WIDTH, WIN_HEIGHT }), TAB_NAME);
    Menu menu(window,0);
    menu.menuWindow();
    return 0;
}
