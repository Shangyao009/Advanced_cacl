#include <iostream>
#include <vector>
#include <string>
#include <math.h>

std::vector<std::string> split_str(std::string str, char seperator)
{
	std::vector<std::string> splited_str_vector = {};
	std::string str_splited;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == seperator)
		{
			splited_str_vector.push_back(str_splited);
			str_splited = "";
		}
		else if (str[i] != seperator)
		{
			str_splited += str[i];
			if (i == str.length() - 1)
			{
				splited_str_vector.push_back(str_splited);
			}
		}
	}
	return splited_str_vector;
}

void strip_front(std::string& str)
{
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			str.erase(0, i);
			break;
		}
	}
}

void strip_back(std::string& str)
//can't let it just return in certain circumstances? or return different type value?
{
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			if (i < str.length() - 1)
			{
				str.erase(i + 1, str.length());
			}
			break;
		}
	}
}

std::string strip(std::string& str)
{
	strip_front(str);
	strip_back(str);
	return str;
}

std::vector<int> find_str(std::string str, std::string str_to_be_found)
{
	bool matched = false;
	std::vector<int> index_vector;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == str_to_be_found[0] && (i + str_to_be_found.length()) <= str.length()) //the first char is matched
		{
			matched = true;
			for (unsigned int n = 1; n < str_to_be_found.length(); n++)
			{
				if (str[i + n] != str_to_be_found[n])
				{
					matched = false;
					break;
				}
				else
				{
					matched = true;
				}
			}
			if (matched)
			{
				index_vector.push_back(i);
			}
			matched = false;
		}
	}
	return index_vector;
}

std::string replace_str(std::string str, std::string str_replaced, std::string replacement)
{
	bool matched = false;
	unsigned int i = 0;
	while (true)
	{
		int len = str.length();
		if (i < len)
		{
			if (str[i] == str_replaced[0] && (i + str_replaced.length()) <= str.length()) //the first char is matched
			{
				matched = true;
				for (unsigned int n = 1; n < str_replaced.length(); n++)
				{
					if (str[i + n] != str_replaced[n])
					{
						matched = false;
						break;
					}
					else
					{
						matched = true;
					}
				}
				if (matched)
				{
					str.replace(i, str_replaced.length(), replacement); //replace the certain str
					i += replacement.length() - 1; //not need to check the replaced part
				}
				matched = false;
			}
			i++;
		}
		else
		{
			return str;
		}
	}
}

float _round_(float input_num, int digit)
{
	float num = std::pow(10, digit);
	return (std::round(input_num * num)) / num;
}

std::vector<std::string> slicing(std::vector<std::string> const & arr, int X, int Y)
{

	// Starting and Ending iterators
	auto start = arr.begin() + X;
	auto end = arr.begin() + Y + 1;

	// To store the sliced vector
	std::vector<std::string> result(Y - X + 1);

	// Copy vector using copy function()
	copy(start, end, result.begin());

	// Return the final sliced vector
	return result;
}