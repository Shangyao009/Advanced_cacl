#pragma once
#include "Setting.h"
#include <SFML/Graphics.hpp>

class Button
    : public sf::Drawable
{
public:
    static sf::Vector2f mouse_position;
    std::string name;
    Setting setting;
    sf::Text button_text;
    sf::RectangleShape button_shape;
    float button_x; float button_y;
    float text_x; float text_y;

    float get_button_width();
    float get_button_height();
    float get_txt_width();
    float get_txt_height();

    sf::Vector2f get_button_upleft_pos();
    sf::Vector2f get_button_upright_pos();
    sf::Vector2f get_button_dwleft_pos();
    sf::Vector2f get_button_dw_right_pos();
    sf::Vector2f get_button_center_pos();

    void set_button_upleft_pos(float x_pos, float y_pos);
    void set_button_upright_pos(float x_pos, float y_pos);
    void set_button_dwleft_pos(float x_pos, float y_pos);
    void set_button_dw_right_pos(float x_pos, float y_pos);
    void set_button_center_pos(float x_pos, float y_pos);
    void set_button_color(sf::Color &color);
    void set_button_size(float width, float height);

    void set_font(sf::Font &font);
    void set_txt(std::string &txt);
    void set_char_size(unsigned int size);
    void set_txt_color(sf::Color &color);
    void set_txt_pos(float x_pos, float y_pos);

    void set_text_middle_y();
    void set_text_middle_x();
    void set_text_center();

    /*virtual void update_button() = 0;
    virtual void update_button_txt() = 0;
    virtual void main() = 0;*/

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:

private:

};