#include"GUI.hpp"

void Procon32::GUI::draw() 
{
	bigFont(U"Hello World!").draw(100, 100, Palette::Red);
}

void Procon32::GUI::dataUpdate()
{

}

Procon32::GUI::GUI()
{
	bigFont = Font(30, Typeface::Bold);
	smallFont = Font(24, Typeface::Bold);

	test = Font((int32)(50, 0.46));
}

Procon32::GUI::~GUI()
{
}