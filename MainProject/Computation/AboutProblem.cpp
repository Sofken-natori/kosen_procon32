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
			data.SetProblemInfo(line, "None", i);
			break;
		case 1:
			//Width,Height
			line.erase(0, 2);
			findSpace = line.find(" ");

			for (int j = 0; j < findSpace; j++)first += line[j];
			for (int j = findSpace; j < line.size(); j++)second += line[j];

			data.SetProblemInfo(first, second, i);

			break;
		case 2:
			//SelectableTimes

			line.erase(0, 2);
			data.SetProblemInfo(line, "None", i);

			break;
		case 3:
			//SelectiveRate ExchangeRate
			line.erase(0, 2);
			findSpace = line.find(" ");

			for (int j = 0; j < findSpace; j++)first += line[j];
			for (int j = findSpace; j < line.size(); j++)second += line[j];

			data.SetProblemInfo(first, second, i);

			break;
		case 4:
			//PixelWidth PixelHeight
			findSpace = line.find(" ");

			for (int j = 0; j < findSpace; j++)first += line[j];
			for (int j = findSpace; j < line.size(); j++)second += line[j];

			data.SetProblemInfo(first, second, i);

			break;
		case 5:
			//MaxRGBChannel
			data.SetProblemInfo(line, "None", i);
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

	for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
		case 0:
			writing_file << data.GetProblemInfo(i);
			writing_file << std::endl;
			break;
		case 1:
			writing_file << data.GetProblemInfo(i);
			writing_file << std::endl;
			break;
		case 2:
			writing_file << data.GetProblemInfo(i);
			writing_file << std::endl;
			break;
		case 3:
			writing_file << data.GetProblemInfo(i);
			writing_file << std::endl;
			break;
		case 4:
			writing_file << data.GetProblemInfo(i);
			writing_file << std::endl;
			break;
		case 5:
			writing_file << data.GetProblemInfo(i);
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