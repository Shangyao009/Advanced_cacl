#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Setting
{
public:
    float width = 120.f;
    float height = 50.f;

    sf::Color default_color = sf::Color(255, 255, 255);
    sf::Color touched_color = sf::Color(200, 200, 200);
   
    sf::Font font;
    sf::Color font_color = sf::Color(0, 0, 0);
    int font_size = 24;

    Setting();
    void update_dynamic_var();
};