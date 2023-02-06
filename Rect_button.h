#pragma once
#include "Setting.h"

class RectButton
    : public sf::Drawable
{
private:
    Setting setting;
public:

    static sf::Vector2f mouse_position;  
    
    std::string name;
    std::string text;

    float width;
    float height;
    sf::Color default_color;
    sf::Color touched_color;

    sf::Vector2f rect_upleft;
    sf::Vector2f rect_bottomleft;
    sf::Vector2f rect_upright;
    sf::Vector2f rect_bottomright;
    sf::Vector2f rect_center;

    RectButton(Setting &setting,std::string name, std::string text);

    sf::Vector2f get_position();
    void set_position(float x_position, float y_position);  
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update_button();
    bool check_mouse_touched() const;

private:    
    sf::RectangleShape shape;
    sf::Text button_text;
    sf::Font font;
    int font_size;
    sf::Color font_color;
    float x = 0.f; float y = 0.f;
    void text_setup();
    void update_position();
};