#include "Button.h"

float Button::get_button_width()
{
	return button_shape.getSize().x;
}

float Button::get_button_height()
{
	return button_shape.getSize().y;
}

float Button::get_txt_width()
{
	float width = 10.f;
	//width = button_text.getLocalBounds().width;
	return width;
}	

float Button::get_txt_height()
{
	return button_text.getLocalBounds().height;
}

sf::Vector2f Button::get_button_upleft_pos()
{
	float x_position = button_x;
	float y_position = button_y;
	sf::Vector2f position(x_position, y_position);
	return position;
}

sf::Vector2f Button::get_button_upright_pos()
{
	float x_position = button_x + get_button_width();
	float y_position = button_y;
	sf::Vector2f position(x_position, y_position);
	return position;
}

sf::Vector2f Button::get_button_dwleft_pos()
{
	float x_position = button_x;
	float y_position = button_y + get_button_height();
	sf::Vector2f position(x_position, y_position);
	return position;
}

sf::Vector2f Button::get_button_dw_right_pos()
{
	float x_position = button_x + get_button_width();
	float y_position = button_y + get_button_height();
	sf::Vector2f position(x_position, y_position);
	return position;
}

sf::Vector2f Button::get_button_center_pos()
{
	float x_position = button_x + get_button_width()/2;
	float y_position = button_y + get_button_height()/2;
	sf::Vector2f position(x_position, y_position);
	return position;
}


void Button::set_button_upleft_pos(float x_pos, float y_pos)
{
	button_x = x_pos;
	button_y = y_pos;
	sf::Vector2f button_position(button_x, button_y);
	button_shape.setPosition(button_position);
}

void Button::set_button_upright_pos(float x_pos, float y_pos)
{
	button_x = x_pos - get_button_width();
	button_y = y_pos;
	sf::Vector2f button_position(button_x, button_y);
	button_shape.setPosition(button_position);
}

void Button::set_button_dwleft_pos(float x_pos, float y_pos)
{
	button_x = x_pos;
	button_y = y_pos - get_button_height();
	sf::Vector2f button_position(button_x, button_y);
	button_shape.setPosition(button_position);
}

void Button::set_button_dw_right_pos(float x_pos, float y_pos)
{
	button_x = x_pos - get_button_width();
	button_y = y_pos - get_button_height();
	sf::Vector2f button_position(button_x, button_y);
	button_shape.setPosition(button_position);
}

void Button::set_button_center_pos(float x_pos, float y_pos)
{
	button_x = x_pos - get_button_width()/2;
	button_y = y_pos - get_button_height()/2;
	sf::Vector2f button_position(button_x, button_y);
	button_shape.setPosition(button_position);
}

void Button::set_button_color(sf::Color &color)
{
	button_shape.setFillColor(color);
}

void Button::set_button_size(float width, float height)
{
	button_shape.setSize(sf::Vector2f(width, height));
}

void Button::set_font(sf::Font &font)
{
	button_text.setFont(font);
}

void Button::set_txt(std::string &txt)
{
	button_text.setString(txt);
}

void Button::set_char_size(unsigned int size)
{
	button_text.setCharacterSize(size);
}

void Button::set_txt_color(sf::Color &color)
{
	button_text.setFillColor(color);
}

void Button::set_txt_pos(float x_pos, float y_pos)
{
	text_x = x_pos;
	text_y = y_pos;
	button_text.setPosition(sf::Vector2f(x_pos,y_pos));
}

void Button::set_text_middle_y()
{
	set_txt_pos(text_x, button_y + get_button_height() / 2 - get_txt_height() / 2);
}

void Button::set_text_middle_x()
{
	set_txt_pos(button_x + get_button_width() / 2 - get_txt_width() / 2, text_y);
}

void Button::set_text_center()
{
	float pos_x = button_x + get_button_width() / 2 - get_txt_width() / 2;
	float pos_y = button_y + get_button_height() / 2 - get_txt_height() / 2;
	set_txt_pos(pos_x,pos_y);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(button_shape);
	target.draw(button_text);
	return;
}

