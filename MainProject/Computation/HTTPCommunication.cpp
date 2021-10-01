#pragma warning(disable: 4996)
#include"HTTPCommunication.hpp"

void Procon32::HTTPCommunication::GETProblem()
{
	curl = curl_easy_init();

	fp = fopen("C:/Users/óÈñÿê∞ìl/source/repos/KosenProcon32-GUI_unit/App/Game/ProblemImage.ppm", "wb");
	curl_easy_setopt(curl, CURLOPT_URL, GET_URL);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	res = curl_easy_perform(curl);
	fclose(fp);
	curl_easy_cleanup(curl);
}

void Procon32::HTTPCommunication::POSTAnswer()
{


}

Procon32::HTTPCommunication::HTTPCommunication()
{	
	GET_URL = "https://procon32-practice.kosen.work/problem.ppm";
	POST_URL = "https://procon32-practice.kosen.work/";
}

Procon32::HTTPCommunication::~HTTPCommunication()
{
}