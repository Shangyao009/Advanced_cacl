#pragma once
#include "Button.h"
#include <functional>

class RectButtonTest
    : public Button
{
public:
    static Setting setting;
    static sf::Vector2f mouse_position;
    static bool mouse_left_clicked;
    static bool display_clear;
    std::string text;

    std::function<void(void)> when_clicked_; //map
    //functor --> class act as a func --> as it overload/overide operator(Ex:({[,) to run certain func
    // [] --> if x this, func can't recognice when_clicked as it is in class,
    // it need this to acess to this func (for variable which don't need to input when call)
    //  int i = 100;
    //  auto lambda = [&i](int num = 0) {cout << i - num; };
    //  lambda(2);
    // () --> get parameter/input
    
    //std::function<void (void)> func; //<function type (function parameter)>
    RectButtonTest(std::string name, std::string text, float x, float y);
        //std::function<void(RectButtonTest& RectButton)> &func );
    RectButtonTest() = default;
    bool check_mouse_touched() const;
    bool is_clicked() const;
    void update_button();
    //void set_when_clicked_func(std::function<void(void)>& func);
    //void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void when_clicked_default();
    void when_clicked_equal();
    void when_clicked_del();
    void when_clicked_cls();

};


