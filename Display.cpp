#include "Display.h"

std::string Display::display_text;

Display::Display(Setting& Setting, std::string name = "Display", std::string text = "")
    :RectButton(Setting, name, text),
    setting(Setting)
{
    x = 0.f;
    y = 0.f;
    shape_setup(setting.display_width,setting.display_height,x,y);
}

float Display::get_width()
{
    return setting.display_width;
}

float Display::get_height()
{
    return setting.display_height;
}

void Display::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //std::cout << "ID " << id << " RectButton is printed!" << std::endl;
    target.draw(shape);
    target.draw(button_text);
}

void Display::update_text()
{
    Display::text = display_text;
    text_setup();
}

void Display::text_setup()
{
    //text under Class Drawable and Transformable
    button_text.setFont(setting.font);
    button_text.setString(text);
    button_text.setCharacterSize(setting.font_size);
    button_text.setFillColor(setting.font_color);
    button_text.setPosition(sf::Vector2f(x + 10, y + 10));
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}