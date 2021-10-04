#pragma warning(disable: 4996)
#include"HTTPCommunication.hpp"

//GET
void Procon32::HTTPCommunication::GETProblem()
{
	curl = curl_easy_init();

	fp = fopen("C:/Users/鈴木晴斗/source/repos/KosenProcon32-GUI_unit/App/Game/ProblemImage.ppm", "wb");
	curl_easy_setopt(curl, CURLOPT_URL, GET_URL);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	res = curl_easy_perform(curl);
	fclose(fp);
	curl_easy_cleanup(curl);
}

//POST 一応動くけどなんかおかしい気がする
void Procon32::HTTPCommunication::POSTAnswer()
{
	curl = curl_easy_init();

	//一回テキストファイルの中身をstringに代入
	std::ifstream ifs("Data/answer3.txt");
	std::string str, line;
	while (getline(ifs, line)) {
		str += line +"\r"+ "\n";
	}

	//std::cout << str << std::endl;

	curl_easy_setopt(curl, CURLOPT_URL, POST_URL);
	curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, postList);
	curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, str.c_str());
	curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.55.1");

	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
}

Procon32::HTTPCommunication::HTTPCommunication()
{	

	postList = NULL;
	postList = curl_slist_append(postList, "procon-token: ");
	postList = curl_slist_append(postList, "Content - Type: application/txt");

	
	GET_URL = "https://procon32-practice.kosen.work/problem.ppm";
	POST_URL = "https://procon32-practice.kosen.work/";
}

Procon32::HTTPCommunication::~HTTPCommunication()
{
}