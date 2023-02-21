#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Rect_button.h"

sf::Vector2f RectButton::mouse_position;  //static var is not a part of class
bool RectButton::mouse_left_clicked;

class Display;

RectButton::RectButton(Setting& Setting, std::string name, std::string text)
    :setting(Setting),
    //shape(sf::Vector2f(setting.width, setting.height)),
    name(name),
    text(text)
{
    shape_setup(setting.width, setting.height, x, y);
    //set_topleft_position(x,y);
    shape.setFillColor(setting.default_color);
    text_setup();
}

void RectButton::shape_setup(float width, float height, float x, float y)
{
    shape.setSize(sf::Vector2f(width, height));
    set_topleft_position(x,y);
}

float RectButton::get_width()
{
    return setting.width;
}

float RectButton::get_height()
{
    return setting.height;
}

void RectButton::set_topleft_position(float x_position, float y_position)
{
    x = x_position;
    y = y_position;
    sf::Vector2f button_position(x, y);
    shape.setPosition(button_position);
}

void RectButton::set_topright_position(float x_position, float y_position)
{
    x = x_position - get_width();
    y = y_position;
    sf::Vector2f button_position(x, y);
    shape.setPosition(button_position);
}

void RectButton::set_bottomleft_position(float x_position, float y_position)
{
    x = x_position;
    y = y_position - get_height();
    sf::Vector2f button_position(x, y);
    shape.setPosition(button_position);
}

void RectButton::set_bottomright_position(float x_position, float y_position)
{
    x = x_position - get_width();
    y = y_position - get_height();
    sf::Vector2f button_position(x, y);
    shape.setPosition(button_position);
}

void RectButton::set_center_position(float x_position, float y_position)
{
    x = x_position - get_width()/2;
    y = y_position - get_height()/2;
    sf::Vector2f button_position(x, y);
    shape.setPosition(button_position);
}

sf::Vector2f RectButton::get_topleft_position()
{
    float x_position = x;
    float y_position = y;
    sf::Vector2f position(x_position, y_position);
    return position;
}

sf::Vector2f RectButton::get_topright_position()
{
    float x_position = x + get_width();
    float y_position = y;
    sf::Vector2f position(x_position, y_position);
    return position;
}

sf::Vector2f RectButton::get_bottomleft_position()
{
    float x_position = x;
    float y_position = y + get_height();
    sf::Vector2f position(x_position, y_position);
    return position;
}

sf::Vector2f RectButton::get_bottomright_position()
{
    float x_position = x + get_width();
    float y_position = y + get_height();
    sf::Vector2f position(x_position, y_position);
    return position;
}

sf::Vector2f RectButton::get_center_position()
{
    float x_position = x + get_width() / 2;
    float y_position = y + get_height() / 2;
    sf::Vector2f position(x_position, y_position);
    return position;
}

void RectButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //std::cout << "ID " << id << " RectButton is printed!" << std::endl;
    target.draw(shape);
    target.draw(button_text);
}

void RectButton::text_setup()
{
    //text under Class Drawable and Transformable
    button_text.setFont(setting.font);
    button_text.setString(text);
    button_text.setCharacterSize(setting.font_size);
    button_text.setFillColor(setting.font_color);
    set_center_text(get_center_position());

    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void RectButton::set_center_text(float x_position, float y_position)
{
    //Get the local bounding rectangle of the entity
    float text_width = button_text.getLocalBounds().width;
    float text_height = button_text.getLocalBounds().height;
    
    button_text.setPosition(sf::Vector2f(x_position - text_width / 2, y_position - text_height / 2));
    //set position left top position
}

void RectButton::set_center_text(sf::Vector2f position)
{
    //Get the local bounding rectangle of the entity
    float text_width = button_text.getLocalBounds().width;
    float text_height = button_text.getLocalBounds().height;

    button_text.setPosition(sf::Vector2f(position.x - text_width / 2, position.y - text_height / 2));
    //set position left top position
}

bool RectButton::check_mouse_touched() const
{
    bool button_touched = false;
    float mouse_x = mouse_position.x; float mouse_y = mouse_position.y;
    if (mouse_x >= x && mouse_x <= x + setting.width && mouse_y >= y && mouse_y <= y + setting.height)
    {
        button_touched = true;
    }
    return button_touched;
}

bool RectButton::is_clicked()
{
    if (check_mouse_touched() && mouse_left_clicked) { return true; }
    else { return false; }
}

void RectButton::main()
{
    if (is_clicked())
    {
        std::cout << "button " << name << " clicked : True \n";
        mouse_left_clicked = false;
    }
}

void RectButton::update_button()
{
    //set_upleft_position(mouse_position.x,mouse_position.y);
    if (check_mouse_touched() == true)
    {
        shape.setFillColor(setting.touched_color);
    }
    else
    {
        shape.setFillColor(setting.default_color);
    }
    main();
    RectButton::mouse_left_clicked = false;
}

void RectButton::append_display_text(std::string str)
{
    //Display::display_text += str;
}
