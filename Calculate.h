#pragma once

#define multiply(x,y) x*y 
#define divide(x,y) x/y
#define sum(x,y) x+y
#define minus(x,y) x-y
#define power(x,y) float a=x;for(int i=0;i<(y-1);i++){x*=a;} //std::pow(x,y) 

//stringstream
//iomanip

std::string calc_ques(std::string& ques_str, int show_decimal);
