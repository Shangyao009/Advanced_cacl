#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Rect_button.h"
#include "Setting.h"

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
    RectButton button(setting,"id 1","1");
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

            case sf::Event::KeyPressed:
                window.close();
                break;
            }
        }

        sf::Vector2i mouse_position  = sf::Mouse::getPosition(window);
        RectButton::mouse_position.x = mouse_position.x;
        RectButton::mouse_position.y = mouse_position.y;

        window.clear();
        button.update_button();
        window.draw(button);
        window.display();
    }

    return 0;
}