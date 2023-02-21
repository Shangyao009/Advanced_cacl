#pragma once
#include <iostream>
#include <array>
#include <string>
#include "Setting.h"
#include <SFML/Graphics.hpp>
//class , struct , datatype
static const char num_button[] = "0123456789";
static char operators_button[] = "+-*/()^.=";
constexpr int total = sizeof(num_button) - 1 + sizeof(operators_button) - 1;
static std::string total_button = std::string(num_button )+ std::string(operators_button);

std::array<std::string,total > get_Rect_buts_name_arr();
std::array<std::string, total> get_Rect_buts_txt_arr();
std::array<sf::Vector2f, total> get_Rect_buts_pos_arr(Setting &setting);