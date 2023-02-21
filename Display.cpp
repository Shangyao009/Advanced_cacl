#include "Display.h"

sf::Vector2f Display::mouse_position;
bool Display::mouse_left_clicked;
std::string Display::text;

Display::Display(Setting& Setting, std::string Name)
{
    text = "";
    setting = Setting;
    button_x = setting.display_x;
    button_y = setting.display_y;
    name = Name;
    display_box_length = setting.display_box_length;

    set_button_size(setting.display_width, setting.display_height);
    set_button_upleft_pos(button_x, button_y);
    set_button_color(setting.default_color);

    set_txt(text);
    set_font(setting.font);
    set_char_size(setting.display_font_size);
    set_txt_color(setting.font_color);

    set_txt_pos(button_x + 10.f, 0.f);
    set_text_middle_y();
}


bool Display::check_mouse_touched() const
{
    bool button_touched = false;
    float mouse_x = mouse_position.x; float mouse_y = mouse_position.y;
    if (mouse_x >= button_x && mouse_x <= button_x + setting.display_width && mouse_y >= button_y && mouse_y <= button_y + setting.display_height)
    {
        button_touched = true;
    }
    return button_touched;
}

bool Display::is_clicked() const
{
    if (check_mouse_touched() && mouse_left_clicked) { return true; }
    else { return false; }
}

void Display::update_button()
{
    //set_upleft_position(mouse_position.x,mouse_position.y);
    if (check_mouse_touched() == true)
    {
        button_shape.setFillColor(setting.touched_color);
        if (is_clicked())
        {
            std::cout << "button " << name << " clicked : True \n";
            Display::mouse_left_clicked = false;
        }
    }
    else
    {
        button_shape.setFillColor(setting.default_color);
    }
    Display::mouse_left_clicked = false;
}

void Display::update_txt()
{
    set_txt(Display::text);
    set_text_middle_y();
}

void Display::update()
{
    update_txt();
    //update_button();
}
