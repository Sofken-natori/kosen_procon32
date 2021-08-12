#include"GUI.hpp"

void Procon32::GUI::draw()
{
	//確認用　いずれ消してください
	bigFont(U"YokoLength is").draw(0, 0, Palette::Black);
	smallFont(U"TateLength is").draw(0, 50, Palette::Blue);
	bigFont(YokoLength).draw(300, 0, Palette::Black);
	smallFont(TateLength).draw(300, 50, Palette::Blue);

	
}

Procon32::GUI::GUI()
{

	bigFont = Font(35, Typeface::Bold);
	smallFont = Font(26, Typeface::Bold);



	testFont = Font(5, Typeface::Bold);
}

Procon32::GUI::~GUI()
{

}