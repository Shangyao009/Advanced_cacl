#include <SFML/Graphics.hpp>
int frame_rate = 60;

sf::Clock Clock;

//window.setframeratelimit()
void clock_fps(int fps)
{
    float time_per_frame = 1 / fps;
    while (true)
    {
        if (::Clock.getElapsedTime().asSeconds() >= time_per_frame)
        {
            Clock.restart();
            break;
        }
    }
}