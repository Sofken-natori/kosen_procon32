#include "KosenProcon32.hpp"
#include "GUI.hpp"

void Main() {

	Window::SetTitle(U"KosenProcon32");
	Window::SetStyle(WindowStyle::Sizable);





	Procon32::GUI gui;

	while (System::Update()) {
		gui.draw();
	}
}