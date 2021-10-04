#pragma warning(disable: 4996)
#include"HTTPCommunication.hpp"

//GET
void Procon32::HTTPCommunication::GETProblem()
{
	curl = curl_easy_init();

	fp = fopen("Data/bbb.ppm", "wb");
	curl_easy_setopt(curl, CURLOPT_URL, comData.GET_URL.c_str());
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
	std::ifstream ifs("Data/answer4.txt");
	std::string str, line;
	while (getline(ifs, line)) {
		str += line +"\r"+ "\n";
	}

	//std::cout << str << std::endl;

	curl_easy_setopt(curl, CURLOPT_URL, comData.POST_URL.c_str());
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
	// JSONデータの読み込み。
	std::ifstream ifs("Data/GameData.json", std::ios::in);
	if (ifs.fail()) {
		std::cerr << "failed to read test.json" << std::endl;
	}
	const std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	ifs.close();

	// JSONデータを解析する。
	picojson::value v;
	const std::string err = picojson::parse(v, json);
	if (err.empty() == false) {
		std::cerr << err << std::endl;
	}

	picojson::object& obj = v.get<picojson::object>();
	comData.GET_URL = obj["GET_URL"].get<std::string>();
	comData.POST_URL = obj["POST_URL"].get<std::string>();
	comData.Token = obj["Token"].get<std::string>();

	postList = NULL;
	postList = curl_slist_append(postList, ("procon-token: " + comData.Token).c_str());
	postList = curl_slist_append(postList, "Content - Type: application/txt");
}

Procon32::HTTPCommunication::~HTTPCommunication()
{
}