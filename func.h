#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

std::vector<std::string> split_str(std::string str, char seperator);
void strip_front(std::string& str);
void strip_back(std::string& str);
std::string strip(std::string& str);
std::vector<int> find_str(std::string str, std::string str_to_be_found);
std::string replace_str(std::string str, std::string str_replaced, std::string replacement);
float _round_(float input_num, int digit);
std::vector<std::string> slicing(std::vector<std::string> const& arr, int X, int Y);
