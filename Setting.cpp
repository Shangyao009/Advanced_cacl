#include "Setting.h"
#include <algorithm>

Setting::Setting()

{
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "arial.ttf file load unsucessfully" << "\n";
    }
    display_box_length = get_display_box_len();
}

float Setting::get_display_box_len()
{
    return std::max(display_width*0.8f, display_width-20.0f);
}