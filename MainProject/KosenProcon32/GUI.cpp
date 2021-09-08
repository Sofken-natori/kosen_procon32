#include"GUI.hpp"

void Procon32::GUI::draw() 
{
	Line(1020, 0, 1020, 720).draw(10, Palette::Black);
	bigFont(Game_Info1).draw(Arg::bottomCenter(1150, 100), Palette::Black);
	bigFont(Game_Info2).draw(Arg::bottomCenter(1150, 300), Palette::Black);
	bigFont(Game_Info3).draw(Arg::bottomCenter(1150, 500), Palette::Black);
	smallFont(Image_Info1).draw(Arg::topLeft(700, 10), Palette::Black);
	smallFont(Image_Info2).draw(Arg::topLeft(700, 40), Palette::Black);
	smallFont(Image_Info3).draw(Arg::topLeft(700, 70), Palette::Black);
	smallFont(Image_info4).draw(Arg::topLeft(700, 100), Palette::Black);
	smallFont(Image_info5).draw(Arg::topLeft(700, 130), Palette::Black);
	smallFont(Image_info6).draw(Arg::topLeft(700, 160), Palette::Black);

	bigFont(U"Hello World!").draw(100, 100, Palette::Red);
}

void Procon32::GUI::dataUpdate()
{

}

Procon32::GUI::GUI()
{
	bigFont = Font(32, Typeface::Bold);
	smallFont = Font(20, Typeface::Bold);

	test = Font((int32)(50, 0.46));
}

Procon32::GUI::~GUI()
{
}