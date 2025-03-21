#include "TextFont.h"

TextFont::TextFont()
{
    Font font;
    LoadFont();
}
void TextFont::SetText(Text& text, string str) {
    text.setString(str);
    text.setFillColor(Color::White);
    text.setCharacterSize(24);
}

void TextFont::LoadFont() {
    if (!font.openFromFile("res/Font/roboto.ttf")) {
        cout << "Font not found" << endl;
    }
}

Font TextFont::getFont()
{
    return font;
}
