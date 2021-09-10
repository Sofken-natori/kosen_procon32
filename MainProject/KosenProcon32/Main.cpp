//↓これで警告無視　ないとGETImageFileのfopenでエラー
#pragma warning(disable: 4996)
#include"KosenProcon32.hpp"
#include"GUI.hpp"
#include"HTTPCommunication.hpp"


void GETImageFile()
{
	CURL* curl;
	FILE* fp;
	CURLcode res;
	const char* URL = "https://procon32-practice.kosen.work/problem.ppm";
	char outfilename[FILENAME_MAX] = "bbb.ppm";
	curl = curl_easy_init();

	fp = fopen(outfilename, "wb");
	curl_easy_setopt(curl, CURLOPT_URL, URL);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	res = curl_easy_perform(curl);
	fclose(fp);
	curl_easy_cleanup(curl);
}

void Main()
{

	GETImageFile();



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