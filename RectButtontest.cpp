#include "RectButtontest.h"
#include "Setting.h"
#include "Display.h"
#include "Calculate.h"

sf::Vector2f RectButtonTest::mouse_position;
bool RectButtonTest::mouse_left_clicked;
bool RectButtonTest::display_clear;
Setting RectButtonTest::setting;

RectButtonTest::RectButtonTest(std::string Name, std::string Text, float x,float y)
    //std::function<void(RectButtonTest& RectButton)> &func)
{
    button_y = y;
    button_x = x;
    name = Name;
    text = Text;
    display_clear = false;
    //this -> func = func; //this -> self, private variable

    set_button_size(setting.width, setting.height);
    set_button_upleft_pos(button_x,button_y);
    set_button_color(setting.default_color);

    set_txt(text);
    set_font(setting.font);
    set_char_size(setting.button_font_size);
    set_txt_color(setting.font_color);
    set_text_center();
}

bool RectButtonTest::check_mouse_touched() const
{
    bool button_touched = false;
    float mouse_x = mouse_position.x; float mouse_y = mouse_position.y;
    if (mouse_x >= button_x && mouse_x <= button_x + setting.width && mouse_y >= button_y && mouse_y <= button_y + setting.height)
    {
        button_touched = true;
    }
    return button_touched;
}

bool RectButtonTest::is_clicked() const
{
    if (check_mouse_touched() && mouse_left_clicked) { return true; }
    else { return false; }
}

void RectButtonTest::update_button()
{
    //set_upleft_position(mouse_position.x,mouse_position.y);
    if (check_mouse_touched() == true)
    {
        set_button_color(setting.touched_color);
        if (is_clicked())
        {
            when_clicked_= [this](){this->when_clicked_default(); };
            when_clicked_();
        }
    }
    else
    {
        set_button_color(setting.default_color);
    }
    //RectButtonTest::mouse_left_clicked = false;
}

void RectButtonTest::when_clicked_default()
{
    if (text == "=")
    {
        std::cout << "button " << name << " clicked : True \n";
        if (display_clear)
        {
            Display::text = "";
            return;
        }
        
        Display::text = calc_ques(Display::text, setting.ans_show_decimal);
        display_clear = true;
    }
    else 
    {
        if (display_clear) 
        {
            Display::text = "";
            display_clear = false;
        }
        std::cout << "button " << name << " clicked : True \n";
        Display::text += text;
    }
}
