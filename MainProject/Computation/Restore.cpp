#include"Restore.hpp"

void Procon32::Restore::RestoreImage()
{
	while (S != "END")
	{
		std::cin >> S;

		if (S == "SWAP")
		{

		}

		if (S == "ROTATION")
		{

		}

		if (S == "RANDOM_SWAP")
		{

		}

		if (S == "RANDOM_ROTATION")
		{

		}

		if (S == "RANDOM_ALL")
		{

		}

		if (S == "END")break;
	}

	return;
}




//GUI�ǂݎ��p��.ppm��.jpg�ϊ��@���̊֐��͕K�v�Ȃ̂�?
void Procon32::Restore::ConversionImage(cv::Mat img)
{
	cv::imwrite(comData.ProblemImageGUI, img);
}






Procon32::Restore::Restore()
{
	// JSON�f�[�^�̓ǂݍ��݁B
	std::ifstream ifs("Data/GameData.json", std::ios::in);
	if (ifs.fail()) {
		std::cerr << "failed to read GameData.json" << std::endl;
	}
	const std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	ifs.close();

	// JSON�f�[�^����͂���B
	picojson::value v;
	const std::string err = picojson::parse(v, json);
	if (err.empty() == false) {
		std::cerr << err << std::endl;
	}

	picojson::object& obj = v.get<picojson::object>();
	comData.ProblemImagePath = obj["ProblemImagePath"].get<std::string>();
	comData.ProblemImageGUI = obj["ProblemImage-GUI"].get<std::string>();

	piece_size = data.PixelWidth / data.Width;
}




Procon32::Restore::~Restore()
{
}