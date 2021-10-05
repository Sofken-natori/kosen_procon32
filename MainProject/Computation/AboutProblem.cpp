#include"AboutProblem.hpp"

void Procon32::AboutProblem::GETProblemInfo()
{
	std::ifstream ProblemFile;
	ProblemFile.open(comData.ProblemImagePath);
	if (!ProblemFile)
	{
		std::cerr << "The file could not be opened." << std::endl;
		return;
	}

	Procon32::GameData data;

	for (int i = 0; i < 6; i++)
	{
		std::string line, first, second;
		int findSpace = 0;
		std::getline(ProblemFile, line);

		switch (i)
		{
		case 0:
			//MagicNumber
			data.MagicNumber = line;
			break;
		case 1:
			//Width,Height
			line.erase(0, 2);
			findSpace = line.find(" ");

			for (int j = 0; j < findSpace; j++)first += line[j];
			for (int j = findSpace; j < line.size(); j++)second += line[j];

			data.Width = stoi(first);
			data.Height = stoi(second);
			break;
		case 2:
			//SelectableTimes

			line.erase(0, 2);
			data.SelectableTimes = stoi(line);
			break;
		case 3:
			//SelectiveRate ExchangeRate
			line.erase(0, 2);
			findSpace = line.find(" ");

			for (int j = 0; j < findSpace; j++)first += line[j];
			for (int j = findSpace; j < line.size(); j++)second += line[j];

			data.SelectiveRate = stoi(first);
			data.ExchangeRate = stoi(second);

			break;
		case 4:
			//PixelWidth PixelHeight
			findSpace = line.find(" ");

			for (int j = 0; j < findSpace; j++)first += line[j];
			for (int j = findSpace; j < line.size(); j++)second += line[j];

			data.PixelWidth = stoi(first);
			data.PixelHeight = stoi(second);
			break;
		case 5:
			//MaxRGBChannel
			data.MaxRGBChannel = stoi(line);
			break;
		default:
			break;
		}
	}

	ProblemFile.close();

	//data.ShowAll();
}

//GUI読み取り用に画像情報の.txtへの書き込み
void Procon32::AboutProblem::WRITEProblemInfo()
{
	std::ofstream writing_file;
	writing_file.open(comData.ProblemInfoPath, std::ios::trunc);
	if (!writing_file)
	{
		std::cerr << "The file could not be opened." << std::endl;
		return;
	}

	Procon32::GameData data;
	std::string A, B, C;

	for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
		case 0:
			writing_file << data.MagicNumber;
			writing_file << std::endl;
			break;
		case 1:
			A = std::to_string(data.Width);
			B = std::to_string(data.Height);
			C = A + " " + B;
			writing_file << C;
			writing_file << std::endl;
			break;
		case 2:
			C = std::to_string(data.SelectableTimes);
			writing_file << C;
			writing_file << std::endl;
			break;
		case 3:
			A = std::to_string(data.SelectiveRate);
			B = std::to_string(data.ExchangeRate);
			C = A + " " + B;
			writing_file << C;
			writing_file << std::endl;
			break;
		case 4:
			A = std::to_string(data.PixelWidth);
			B = std::to_string(data.PixelHeight);
			C = A + " " + B;
			writing_file << C;
			writing_file << std::endl;
			break;
		case 5:
			C = std::to_string(data.MaxRGBChannel);
			writing_file << C;
			break;
		default:
			break;
		}
	}

	writing_file.close();
}

Procon32::AboutProblem::AboutProblem()
{	// JSONデータの読み込み。
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
	comData.ProblemInfoPath = obj["ProblemInfoPath"].get<std::string>();
}

Procon32::AboutProblem::~AboutProblem()
{
}