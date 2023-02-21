#pragma once
#include "Button.h"

class RectButtonTest
    : public Button
{
public:
    static Setting setting;
    static sf::Vector2f mouse_position;
    static bool mouse_left_clicked;
    static bool display_clear;
    std::string text;


    RectButtonTest(std::string name, std::string text, float x, float y);
    RectButtonTest() = default;
    bool check_mouse_touched() const;
    bool is_clicked() const;
    void update_button();
    //void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void when_clicked();
};


