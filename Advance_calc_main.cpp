#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Setting.h"
#include "Display.h"
#include "RectButtontest.h"
#include "button_properties.h"

std::vector<RectButtonTest> Buttons;
Setting _setting;


void create_buttons()
{
    std::array<std::string, total> Rect_button_name_array = get_Rect_buts_name_arr();
    std::array<std::string, total> Rect_button_text_array = get_Rect_buts_txt_arr();
    std::array<sf::Vector2f, total> Rect_button_pos_array = get_Rect_buts_pos_arr(_setting);
    for (int i = 0; i < total; i++)
    {
        std::string name = Rect_button_name_array[i];
        std::string text = Rect_button_text_array[i];
        float x = Rect_button_pos_array[i].x;
        float y = Rect_button_pos_array[i].y;
        RectButtonTest Button(name, text, x, y);
        Buttons.push_back(Button);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(_setting.window_width, _setting.window_height), "Advanced Calculater");
    RectButtonTest::setting = _setting;
    Display display(_setting,"Display");
    create_buttons();
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                return 0;

            /*
            case sf::Event::KeyPressed:
                window.close();
                break;
            */
            
            case sf::Event::MouseButtonPressed:
                switch (event.key.code)
                {
                case sf::Mouse::Left:
                    RectButtonTest::mouse_left_clicked = true;
                    Display::mouse_left_clicked = true;
                }
            
            /*case sf::Event::MouseButtonReleased:
                switch (event.key.code)
                {
                case sf::Mouse::Left:
                    RectButton::mouse_left_clicked = false;
                }*/
            }
        }

        sf::Vector2i mouse_position  = sf::Mouse::getPosition(window);
        RectButtonTest::mouse_position.x = mouse_position.x;
        RectButtonTest::mouse_position.y = mouse_position.y;
        Display::mouse_position.x = mouse_position.x;
        Display::mouse_position.y = mouse_position.y;

        window.clear();
        display.update();
        for (RectButtonTest button : Buttons)
        { 
            (button).update_button();
            window.draw(button);
        }
        RectButtonTest::mouse_left_clicked = false;
        window.draw(display);
        window.display();
    }
    return 0;
}
