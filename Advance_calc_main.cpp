#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Rect_button.h"
#include "Setting.h"
#include "Display.h"

std::vector<RectButton*> Button_vect;

Setting setting;

void create_button(std::string name, std::string text)
{
    RectButton button(setting,name,text);
    ::Button_vect.push_back(&button);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 700), "Advanced Calculater");
    //RectButton button(setting,"id 1","1");
    Display display(setting);
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            /*case sf::Event::KeyPressed:
                window.close();
                break;
            */
                
            case sf::Event::MouseButtonPressed:
                switch (event.key.code)
                {
                case sf::Mouse::Left:
                    RectButton::mouse_left_clicked = true;
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
        RectButton::mouse_position.x = mouse_position.x;
        RectButton::mouse_position.y = mouse_position.y;

        window.clear();
        //display.update_button();
        //window.draw(button);
        //window.draw(display);
        window.display();
    }

    return 0;
}