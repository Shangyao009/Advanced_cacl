#pragma once
#include "Rect_button.h"

class Display :
	public RectButton
{
public:
	static std::string display_text;
	Setting setting;
	Display(Setting& Setting, std::string name, std::string text);
	float get_width();
	float get_height();
	void update_text();
	void text_setup();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};