#pragma once
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include "Setting.h"
#include <SFML/Graphics.hpp>
#include <functional>

//class , struct , datatype
static const std::string num_button[] = {"0","1","2","3","4","5","6","7","8","9"};
static const std::string operators_button[] = { "+","-","*","/","(",")","^",".","=" };
static constexpr int size_num_button = sizeof(num_button) / sizeof(*num_button);
static constexpr int size_operators_button = sizeof(operators_button) / sizeof(*operators_button);
constexpr int total = size_num_button + size_operators_button;

std::array<std::string,total > get_Rect_buts_name_arr();
std::array<std::string, total> get_Rect_buts_txt_arr();
std::array<sf::Vector2f, total> get_Rect_buts_pos_arr(Setting &setting);