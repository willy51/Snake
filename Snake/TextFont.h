#pragma once

#ifndef DEF_TEXT
#define DEF_TEXT

#include "Global.h"
class TextFont
{
public:
	TextFont();
	void SetText(Text& text, string str);
	void LoadFont();
	Font getFont();
private:
	Font font;
};

#endif // DEF_TEXT
