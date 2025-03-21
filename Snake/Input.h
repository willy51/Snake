#pragma once
#ifndef DEF_INPUT
#define DEF_INPUT

#include "Global.h"

class Input
{
	struct Button { bool up, down, left, right; };
public:
    Input(); 
	void InputHandler(optional<Event> event, RenderWindow& window);
	Button getButton();
private:
	Button button;
	int lastButton;
};

#endif // !DEF_INPUT
    
