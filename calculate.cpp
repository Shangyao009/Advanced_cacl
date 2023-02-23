#include <iostream>
#include <format>
#include <vector>
#include <string>
#include <math.h>
#include "func.h"
#include "Calculate.h"

std::vector<std::string>ques_vec;
std::vector<std::string> math_operators = { "+","-", "*","/","^","(",")" };
bool error_exist = false;

void preprocess_ques_vec(std::vector<std::string> Ques_vec);
void ques_str_to_vec(std::string ques_str);
std::string calculate_next_parentheses(std::vector<std::string> ques_vec);
std::string calculate(std::vector<std::string>& ques_vec);
void calc_pow(std::vector<std::string>& ques_vec);
void calc_multiply_divide(std::vector<std::string>& ques_vec);
void calc_plus_minus(std::vector<std::string>& ques_vec);

void error_report(std::string string);
float isnum(std::string num_string);

std::string ask_ques(std::string question_asked);
std::string set_answer_decimal(float ans, int decimal);

/*
int main()
{	
	while (true)
	{
		::error_exist = false;
		::ques_vec.clear();
		std::string respond;
		respond = ask_ques("Input question? (Q for exit)");
		std::cout << respond <<"\n";
 		if (respond == "Q")
		{
			std::cin.get();
			return 0;
		}
		else
		{
			float answer = calc_ques(respond);
			std::string ans_str = set_answer_decimal(answer,::show_decimal);
			std::cout << "\nanswer is  " + ans_str + " \n";
		}
	}
}
*/
std::string set_answer_decimal(float ans, int decimal)
{
	ans = _round_(ans, decimal);
	std::string ans_str = std::to_string(ans);
	for (int i = 0; i < ans_str.length(); i++)
	{
		if (ans_str[i] == '.')
		{
			ans_str = ans_str.substr(0, i + 1 + decimal);
		}
	}
	//ans_str = std::format(ans_str);
	return ans_str;
}

std::string ask_ques(std::string question_asked)
{
	std::string respond;
	std::cout << question_asked << "\n";
	getline(std::cin, respond);
	return respond;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
										/////Calculation/////

float isnum(std::string num_string)
{
	std::string float_chars = "+-0123456789.";
	for (int i = 0; i < num_string.length(); i++)
	{
		if (float_chars.find(num_string[i]) == std::string::npos) //char not found
		{
			error_report("Char " + num_string.substr(i, 1) + " is undefined!"); //error_exist = True
			return 1.f;
		}
	}
	return std::stof(num_string);
}

void error_report(std::string string = "")
{
	std::cout << string << std::endl;
	::error_exist = true;
}

std::string calc_ques(std::vector<std::string> Ques_vec, 
	int show_decimal)
{
	error_exist = false;
	::ques_vec = {};
	preprocess_ques_vec(Ques_vec);
	//ques_vec = {}
	//ques_str_to_vec(ques_str);

	std::cout << "Ques_vec: ";
	for (std::string element : ::ques_vec)
	{
		std::cout << element << " ";
	}
	std::cout << "\n";
	std::string ans = calculate_next_parentheses(::ques_vec);
	if (::error_exist)
	{
		return "Beyond my ability, Maybe Typo? ";
	}
	else
	{
		float answer = std::stof(ans);
		return set_answer_decimal(answer,show_decimal);
	}
}

void preprocess_ques_vec(std::vector<std::string> Ques_vec)
{
	std::string num_str;
	for (unsigned int i = 0; i < Ques_vec.size(); i++)
	{	//find operator
		if (std::find(::math_operators.begin(),math_operators.end(),Ques_vec[i]) == math_operators.end())
		{
			num_str += Ques_vec[i];
			if (i == Ques_vec.size() - 1)
			{
				::ques_vec.push_back(num_str);
			}
		}
		else if (std::find(::math_operators.begin(), math_operators.end(), Ques_vec[i]) != math_operators.end())
		{
			if (num_str != "") {
				::ques_vec.push_back(num_str);
				num_str = "";
			}
			::ques_vec.push_back(Ques_vec[i]);
		}
	}
	//check available ques
	//add addition rules such as 9(7) = 9*(7)

}

void ques_str_to_vec(std::string ques_str)
{
	std::string num_str;
	strip(ques_str);
	for (unsigned int i = 0; i < ques_str.length(); i++)
	{	//find operator
		if (std::find(::math_operators.begin(), math_operators.end(), std::to_string(ques_str[i])) == math_operators.end() && ques_str[i] != ' ')
		{
			num_str.push_back(ques_str[i]);
			if (i == ques_str.length() - 1)
			{
				::ques_vec.push_back(num_str);
			}
		}
		else if (std::find(::math_operators.begin(), math_operators.end(), std::to_string(ques_str[i])) != math_operators.end())
		{
			if (num_str != "") {
				::ques_vec.push_back(num_str);
				num_str = "";
			}
			::ques_vec.push_back(ques_str.substr(i, 1));
		}
	}
}

void calc_pow(std::vector<std::string>& ques_vec)
{
	int len = ques_vec.size(); int i = 0;
	while (i < len && ::error_exist == false)
	{
		std::string element = ques_vec[i];
		if (element == "^" && i !=0 && i!=len-1)
		{
			float left_num = isnum(ques_vec[i - 1]); float right_num = isnum(ques_vec[i + 1]);
			power(left_num, right_num);
			float result = left_num;
			ques_vec[i - 1] = std::to_string(result);
			ques_vec.erase(ques_vec.begin() + i + 1);
			ques_vec.erase(ques_vec.begin() + i);
			i -= 2;
			len = ques_vec.size();
		}
		i++;
	}
}

void calc_multiply_divide(std::vector<std::string>& ques_vec)
{
	int len = ques_vec.size(); int i = 0;
	while (i < len && ::error_exist == false)
	{
		std::string element = ques_vec[i];
		if ((element == "*" || element == "/") && (i != 0 && i != len - 1))
		{
			float left_num = isnum(ques_vec[i - 1]); float right_num = isnum(ques_vec[i + 1]);
			float result = element == "*" ? multiply(left_num, right_num) : divide(left_num, right_num);
			ques_vec[i - 1] = std::to_string(result);
			ques_vec.erase(ques_vec.begin() + i + 1);
			ques_vec.erase(ques_vec.begin() + i);
			i -= 2;
			len = ques_vec.size();
		}
		i++;
	}
}

void calc_plus_minus(std::vector<std::string>& ques_vec)
{
	if (ques_vec[0] == "-")
	{
		if (ques_vec.size() == 1)
		{
			error_report();
		}
		else
		{
			float num = isnum(ques_vec[1]);
			num *= -1;
			ques_vec[1] = std::to_string(num);
			ques_vec.erase(ques_vec.begin());
		}
	}
	else if (ques_vec[0] == "+")
	{
		ques_vec.erase(ques_vec.begin());
	}

	int len = ques_vec.size(); 
	int i = 0;
	while (i < len && ::error_exist == false)
	{
		std::string element = ques_vec[i];
		if ((element == "+" || element == "-") && (i != len-1))
		{
			float left_num = isnum(ques_vec[i - 1]); 
			float right_num = isnum(ques_vec[i + 1]);
			float result = element == "+" ? sum(left_num, right_num) : minus(left_num, right_num);
			ques_vec[i - 1] = std::to_string(result);
			ques_vec.erase(ques_vec.begin() + i + 1);
			ques_vec.erase(ques_vec.begin() + i);
			i -= 2;
			len = ques_vec.size();
		}
		i++;
	}
}

std::string calculate(std::vector<std::string> &ques_vec)
{	
	calc_pow(ques_vec);
	calc_multiply_divide(ques_vec);
	calc_plus_minus(ques_vec);
	if (::error_exist) { return ""; }
	else if (ques_vec.size() == 1)
	{ 
		float num = isnum(ques_vec[0]);
		std::string result = std::to_string(num);
		return result;
	}
	else
	{ 
		std::cout << "Bug happen in func calculate! \n";
		error_report();
		return "";
	}//raise error
}

std::string calculate_next_parentheses(std::vector<std::string> ques_vec)
{	

	bool have_parentheses = false;
	int parentheses_index = 0;
	have_parentheses = std::find(ques_vec.begin(),ques_vec.end(),"(") != ques_vec.end();
	if (have_parentheses && ::error_exist ==false)
	{
		for (int i = 0; i < ques_vec.size(); i++)  //indexing through ques vec
		{
			if (::error_exist) { break; }
			if (ques_vec[i] == "(")
			{
				parentheses_index = 1;
				for (int n = 1; i + n < ques_vec.size(); n++)
				{
					if (::error_exist) { break; }
					else if (ques_vec[i + n] == "(")
					{
						parentheses_index += 1;
					}
					else if (ques_vec[i + n] == ")")
					{
						parentheses_index -= 1;
						if (parentheses_index < 0) { error_report("Inappropriate Parentheses ! "); return ""; }  //raise exception for (ex: ()) )
						else if (parentheses_index == 0)  //corresponding parentheses found
						{
							std::string result = calculate_next_parentheses(slicing(ques_vec, i + 1, i + n - 1));
							ques_vec[i] = result;
							ques_vec.erase(ques_vec.begin() + i + 1, ques_vec.begin() + i + n + 1);
							i--;
							break; //the ques inside () is solve, move on indexing the ques_vec
						}
					}
				}
				if (parentheses_index > 0) { error_report("Inappropriate Parentheses ! "); return ""; } //raise exception (ex: ((()  )
				continue;
			}
		}
	}
	if (::error_exist == false)
	{
		std::string result = calculate(ques_vec);
		return result;
	}
	else
	{
		return "";
	}
}
