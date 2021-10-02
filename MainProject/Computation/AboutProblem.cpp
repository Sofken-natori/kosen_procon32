#include"AboutProblem.hpp"
#include"GameData.hpp"

void Procon32::AboutProblem::GETProblemInfo()
{
	std::ifstream ProblemFile;
	ProblemFile.open("bbb.ppm");
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
			data.Set(line, "None", i);
			break;
		case 1:
			//Width,Height
			line.erase(0, 2);
			findSpace = line.find(" ");

			for (int j = 0; j < findSpace; j++)first += line[j];
			for (int j = findSpace; j < line.size(); j++)second += line[j];

			data.Set(first, second, i);

			break;
		case 2:
			//SelectableTimes

			line.erase(0, 2);
			data.Set(line, "None", i);

			break;
		case 3:
			//SelectiveRate ExchangeRate
			line.erase(0, 2);
			findSpace = line.find(" ");

			for (int j = 0; j < findSpace; j++)first += line[j];
			for (int j = findSpace; j < line.size(); j++)second += line[j];

			data.Set(first, second, i);

			break;
		case 4:
			//PixelWidth PixelHeight
			findSpace = line.find(" ");

			for (int j = 0; j < findSpace; j++)first += line[j];
			for (int j = findSpace; j < line.size(); j++)second += line[j];

			data.Set(first, second, i);

			break;
		case 5:
			//MaxRGBChannel
			data.Set(line, "None", i);
			break;
		}
	}

	ProblemFile.close();

	data.ShowAll();
}

void Procon32::AboutProblem::WRITEProblemInfo()
{

}

Procon32::AboutProblem::AboutProblem()
{

}

Procon32::AboutProblem::~AboutProblem()
{
}