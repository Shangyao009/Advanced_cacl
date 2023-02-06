#include "Setting.h"

Setting::Setting()
{
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "arial.ttf file load unsucessfully" << "\n";
    }
}

void Setting::update_dynamic_var()
{

}