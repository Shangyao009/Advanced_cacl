#pragma once
#include "Setting.h"

class RectButton
    : public sf::Drawable
{
protected:
    Setting setting;
    sf::RectangleShape shape;

    sf::Text button_text;
    float x = 90.f; //left
    float y = 90.f; //top

    void text_setup();
    void shape_setup(float width, float height, float x,float y);

private:
    void append_display_text(std::string str);

public:

    static bool mouse_left_clicked;
    static sf::Vector2f mouse_position;  
    
    std::string name;
    std::string text;

    RectButton() = default;
    RectButton(Setting &setting,std::string name, std::string text);

    float get_width();
    float get_height();

    void set_topleft_position(float x_position, float y_position);
    void set_topright_position(float x_position, float y_position);
    void set_bottomleft_position(float x_position, float y_position);
    void set_bottomright_position(float x_position, float y_position);
    void set_center_position(float x_position, float y_position);

    sf::Vector2f get_topleft_position();
    sf::Vector2f get_topright_position();
    sf::Vector2f get_bottomleft_position();
    sf::Vector2f get_bottomright_position();
    sf::Vector2f get_center_position();

    void set_center_text(float x_position , float y_position);
    void set_center_text(sf::Vector2f position);

    bool is_clicked();
    void main();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update_button();
    bool check_mouse_touched() const;
};