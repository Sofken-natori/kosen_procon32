#include"Restore.hpp"

void Procon32::Restore::RestoreImage()
{
	cv::Mat image = cv::imread(comData.ProblemImagePath);
	if (image.empty())
	{
		std::cerr << "ProblemImage could not be opened." << std::endl;
	}

	ConversionImage(image);

	return;
}

//GUI読み取り用に.ppm→.jpg変換　この関数は必要なのか?
void Procon32::Restore::ConversionImage(cv::Mat img)
{
	cv::imwrite(comData.ProblemImageGUI, img);
}

Procon32::Restore::Restore()
{
	// JSONデータの読み込み。
	std::ifstream ifs("Data/GameData.json", std::ios::in);
	if (ifs.fail()) {
		std::cerr << "failed to read GameData.json" << std::endl;
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
	comData.ProblemImagePath = obj["ProblemImagePath"].get<std::string>();
	comData.ProblemImageGUI = obj["ProblemImage-GUI"].get<std::string>();
}

Procon32::Restore::~Restore()
{
}