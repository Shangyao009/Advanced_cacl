
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Rect_button.h"

//sf::Vector2f RectButton::mouse_position;  //static var is not a part of class

RectButton::RectButton(Setting& Setting, std::string name, std::string text)
    :setting(Setting),
    
    width(setting.width),
    height(setting.height),
    default_color(setting.default_color),
    touched_color(setting.touched_color),
    font(setting.font),
    font_color(setting.font_color),
    font_size(setting.font_size),

    rect_upleft(x, y),
    rect_bottomleft(x, y + height),
    rect_upright(x + width, y),
    rect_bottomright(x + width, y + height),
    rect_center((x + width)/2, (y + height)/2),
    shape(sf::Vector2f(width, height)),
    name(name),
    text(text)
{
    set_position(x,y);
    shape.setFillColor(default_color);
    text_setup();
}

//void RectButton::set_position(float x_position, float y_position)
//{
//    x = x_position;
//    y = y_position;
//    sf::Vector2f button_position(x, y);
//    shape.setPosition(button_position);
//    update_position();
//}

void RectButton::set_position(float x_position, float y_position)
{
    x = x_position;
    y = y_position;
    sf::Vector2f button_position(x, y);
    shape.setPosition(button_position);
    update_position();
}

void RectButton::update_position()
{
    rect_upleft = sf::Vector2f(x, y);
    rect_bottomleft = sf::Vector2f(x, y + height);
    rect_upright = sf::Vector2f(x + width, y);
    rect_bottomright = sf::Vector2f(x + width, y + height);
    rect_center = sf::Vector2f((x + width) / 2, (y + height) / 2);
}


sf::Vector2f RectButton::get_position()
{
    return shape.getPosition();
}

void RectButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //std::cout << "ID " << id << " RectButton is printed!" << std::endl;
    target.draw(shape);
    target.draw(button_text);
}

void RectButton::text_setup()
{
    // Load font from a file
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "arial.ttf file load unsucessfully" << "\n";
    }

    button_text.setFont(font);
    button_text.setString(text);
    button_text.setCharacterSize(font_size);
    button_text.setFillColor(font_color);
    
    button_text.setPosition(sf::Vector2f(0.f, 0.f));
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

bool RectButton::check_mouse_touched() const
{
    bool button_touched = false;
    float mouse_x = mouse_position.x; float mouse_y = mouse_position.y;
    if (mouse_x >= x && mouse_x <= x + width && mouse_y >= y && mouse_y <= y + height)
    {
        button_touched = true;
    }
    return button_touched;
}

void RectButton::update_button()
{
    //set_upleft_position(mouse_position.x,mouse_position.y);
    if (check_mouse_touched() == true)
    {
        shape.setFillColor(touched_color);
    }
    else
    {
        shape.setFillColor(default_color);
    }
}

//void RectButton::

