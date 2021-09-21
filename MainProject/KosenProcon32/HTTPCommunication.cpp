#include"HTTPCommunication.hpp"

void Procon32::HTTPCommunication::GETProblemImage()
{
	curl = curl_easy_init();

	fp = fopen("bbb.ppm", "wb");
	curl_easy_setopt(curl, CURLOPT_URL, URL);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	res = curl_easy_perform(curl);
	fclose(fp);
	curl_easy_cleanup(curl);
}






Procon32::HTTPCommunication::HTTPCommunication()
{
	URL = "https://procon32-practice.kosen.work/problem.ppm";


}

Procon32::HTTPCommunication::~HTTPCommunication()
{
}