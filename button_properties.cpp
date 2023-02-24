#include "button_properties.h"

std::array<std::string, total> get_total_button()
{
	std::array<std::string, total> total_button;
	for (int i = 0; i < size_num_button; i++)
	{
		total_button[i] = num_button[i];
	}
	for (int i = 0; i < size_operators_button; i++)
	{
		total_button[size_num_button + i] = operators_button[i];
	}
	return total_button;
}

std::array<std::string,total> get_Rect_buts_name_arr()
{
	std::array<std::string, total> total_button = get_total_button();
	std::array<std::string, total> Rect_button_name_array;
	for (int i = 0; i < total_button.size(); i++)
	{
		std::string something;
		something = total_button[i];
		Rect_button_name_array[i] = something + "_but";
	}
	return Rect_button_name_array;
}

std::array<std::string, total> get_Rect_buts_txt_arr()
{
	std::array<std::string, total> total_button = get_total_button();
	std::array<std::string, total> Rect_button_text_array;
	for (int i = 0; i < total_button.size(); i++)
	{
		std::string something;
		something = total_button[i];
		Rect_button_text_array[i] = something;
	}
	return Rect_button_text_array;
}

std::array<sf::Vector2f, total> get_Rect_buts_pos_arr(Setting& setting)
{
	std::array<sf::Vector2f, total>Rect_button_pos_array;
	float x = 15.f;
	float y = 120.f;
	for (int i = 0; i < total; i++)
	{
		sf::Vector2f pos;
		pos.x = x;
		pos.y = y;
		Rect_button_pos_array[i] = pos;
		x += setting.width + 5.f;
		y = (x + setting.width > setting.window_width) ? y + setting.height + 5 : y;
		x = (x + setting.width > setting.window_width) ? 15.f : x;
	}
	return Rect_button_pos_array;
}
