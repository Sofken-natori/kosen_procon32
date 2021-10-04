#include"AboutProblem.hpp"
#include"GameData.hpp"

void Procon32::AboutProblem::GETProblemInfo()
{
	std::ifstream ProblemFile;
	ProblemFile.open("Data/bbb.ppm");
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

//GUI“Ç‚ÝŽæ‚è—p‚É‰æ‘œî•ñ‚Ì.txt‚Ö‚Ì‘‚«ž‚Ý
void Procon32::AboutProblem::WRITEProblemInfo()
{
	std::string filename = "Data/ProblemInfo.txt";
	std::ofstream writing_file;
	writing_file.open(filename, std::ios::trunc);

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
{

}

Procon32::AboutProblem::~AboutProblem()
{
}