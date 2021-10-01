#include"GUI.hpp"

void Procon32::GUI::draw()
{
	Line(1020, 0, 1020, 800).draw(10, Palette::Black);
	bigFont(U"Time").draw(Arg::bottomCenter(1150, 70), Palette::Black);
	bigFont(U"Score").draw(Arg::bottomCenter(1150, 250), Palette::Black);
	bigFont(U"Count").draw(Arg::bottomCenter(1150, 430), Palette::Black);
	bigFont(U"Result").draw(Arg::bottomCenter(1150, 610), Palette::Black);
	smallFont(U"Magig Number").draw(Arg::topLeft(700, 10), Palette::Black);
	smallFont(U"Segments").draw(Arg::topLeft(700, 40), Palette::Black);
	smallFont(U"Selectable Times").draw(Arg::topLeft(700, 70), Palette::Black);
	smallFont(U"Rate").draw(Arg::topLeft(700, 100), Palette::Black);
	smallFont(U"Image Size").draw(Arg::topLeft(700, 130), Palette::Black);
	smallFont(U"Max RGB").draw(Arg::topLeft(700, 160), Palette::Black);
}

Procon32::GUI::GUI()
{
	bigFont = Font(32, Typeface::Bold);
	smallFont = Font(20, Typeface::Bold);
}

Procon32::GUI::~GUI()
{
}
