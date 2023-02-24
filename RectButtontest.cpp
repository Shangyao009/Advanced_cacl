#include "RectButtontest.h"
#include "Setting.h"
#include "Display.h"
#include "Calculate.h"

sf::Vector2f RectButtonTest::mouse_position;
bool RectButtonTest::mouse_left_clicked;
bool RectButtonTest::display_clear;
Setting RectButtonTest::setting;
std::string RectButtonTest::previous_ans;

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
    if (text == "=")
    {
        when_clicked_ = [this]() {std::cout << "button " << name << " clicked : True \n"; when_clicked_equal(); };
    }
    else if (text == "del")
    {
        when_clicked_ = [this]() {std::cout << "button " << name << " clicked : True \n";  when_clicked_del(); };
    }
    else if (text == "cls")
    {
        when_clicked_ = [this]() {std::cout << "button " << name << " clicked : True \n"; when_clicked_cls(); };
    }
    else if (text == "Ans")
    {
        when_clicked_ = [this]() {std::cout << "button " << name << " clicked : True \n"; when_clicked_ans(); };
    }
    else
    {
        when_clicked_ = [this]() {std::cout << "button " << name << " clicked : True \n"; when_clicked_default(); };
    }
    
}

//void RectButtonTest::set_when_clicked_func(std::function<void(void)> &func)
//{
//    when_clicked_ = func;
//}

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
        button_shape.setFillColor(setting.touched_color);
        if (is_clicked())
        {
            when_clicked_();
        }
    }
    else
    {
        button_shape.setFillColor(setting.default_color);
    }
    //RectButtonTest::mouse_left_clicked = false;
}

void RectButtonTest::when_clicked_default()
{
    if (display_clear) 
    {
        Display::ques_vec = {};
        Display::text = "";
        display_clear = false;
    }
    Display::ques_vec.push_back(text);
    Display::text += text;
}

void RectButtonTest::when_clicked_del()
{
    if (display_clear)
    {
        Display::ques_vec = {};
        Display::text = "";
        display_clear = false;
        return;
    }
    if (Display::ques_vec.size() != 0)
    {
        int len_vec = Display::ques_vec.size();
        int len = Display::ques_vec[len_vec-1].length();
        int len_text = Display::text.length();
        Display::text = Display::text.substr(0,len_text-len);
        Display::ques_vec.erase(Display::ques_vec.begin() + len_vec - 1);
    }
}

void RectButtonTest::when_clicked_equal()
{
    if (display_clear)
    {
        Display::ques_vec = {};
        Display::text = "";
        return;
    }
    if (Display::ques_vec.size() > 0)
    {
        Display::text = calc_ques(Display::ques_vec, setting.ans_show_decimal);
        previous_ans = Display::text;
        std::cout << "Previous Ans : " << previous_ans + "\n";
    }
    display_clear = true;
}

void RectButtonTest::when_clicked_cls()
{
    Display::ques_vec = {};
    Display::text = "";
    previous_ans = "";
    display_clear = false;
}

void RectButtonTest::when_clicked_ans()
{
    if (display_clear)
    {
        Display::ques_vec = {};
        Display::text = "";
        display_clear = false;
    }
    if (previous_ans != "")
    {
        std::cout << "Previous Ans = " << previous_ans + "\n";
        Display::ques_vec.push_back(previous_ans);
        Display::text += text;
    }
}