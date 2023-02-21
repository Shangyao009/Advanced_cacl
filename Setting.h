#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Setting
{
public:
    float width = 120.f; //button
    float height = 50.f;

    sf::Color default_color = sf::Color(255, 255, 255);
    sf::Color touched_color = sf::Color(200, 200, 200);
   
    float display_width = 380.f;
    float display_height = 50.f;
    float display_x = 10.f;
    float display_y = 10.f;
    float display_box_length;
    int display_font_size = 24;

    int ans_show_decimal = 2;

    float window_width = 400.f;
    float window_height = 600.f;

    float get_display_box_len();

    sf::Font font;
    sf::Color font_color = sf::Color(100, 100, 100);
    int button_font_size = 24;

    Setting();
};