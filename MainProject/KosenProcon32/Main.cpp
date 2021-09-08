#include"KosenProcon32.hpp"
#include"GUI.hpp"
#include"HTTPCommunication.hpp"

void Main()
{
	Window::Resize(1280, 720);
	Window::SetTitle(U"KosenProcon32");
	Scene::SetScaleMode(ScaleMode::AspectFit);
	Window::SetStyle(WindowStyle::Sizable);
	Scene::SetBackground(ColorF(0.8, 0.9, 1.0));

	Procon32::GUI gui;
	Procon32::HTTPCommunication http;

	gui.dataUpdate();

	while (System::Update())
	{
		gui.draw();

		Circle(Cursor::Pos(), 30).draw(ColorF(1, 0, 0, 0.5));
	}



}