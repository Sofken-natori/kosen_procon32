#include"GUI.hpp"
#include"Generator.hpp"

void Procon32::GUI::draw()
{
	testFont(U"Yoko").draw(0, 0, Palette::Black);
	testFont(U"Tate").draw(0, 50, Palette::Black);
	testFont(YokoLength).draw(60, 0, Palette::Black);
	testFont(TateLength).draw(60, 50, Palette::Black);

	Generator a;

	
}

Procon32::GUI::GUI()
{

	bigFont = Font(35, Typeface::Bold);
	smallFont = Font(26, Typeface::Bold);



	testFont = Font(20, Typeface::Bold);
}

Procon32::GUI::~GUI()
{
}