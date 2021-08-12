﻿#include "KosenProcon32.hpp"
#include "GUI.hpp"

void Main() {

	Window::SetTitle(U"KosenProcon32");
	Window::SetStyle(WindowStyle::Sizable);
	Scene::SetScaleMode(ScaleMode::AspectFit);
	Scene::SetBackground(ColorF(0.8, 0.9, 1.0));




	Procon32::GUI gui;

	while (System::Update()) {
		gui.draw();
	}
}