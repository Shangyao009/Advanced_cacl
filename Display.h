#pragma once
#include "Button.h"
#include "Setting.h"

class Display
    : public Button
{
public:
    float display_box_length;
    static sf::Vector2f mouse_position;
    static bool mouse_left_clicked;
    static std::string text;
    static std::vector<std::string> ques_vec;

    Display(Setting& setting, std::string name);
    sf::Texture display_texture;
    bool check_mouse_touched() const;
    bool is_clicked() const;
    void update_button();
    void update_txt();
    void update();
};
