#include"GameData.hpp"

void Procon32::GameData::ShowAll()
{
	std::cout << "MagicNumber " << MagicNumber << std::endl;
	std::cout << "Width " << Width << std::endl;
	std::cout << "Height " << Height << std::endl;
	std::cout << "SelectableTimes " << SelectableTimes << std::endl;
	std::cout << "Selectiverate " << SelectiveRate << std::endl;
	std::cout << "ExchangeRate " << ExchangeRate << std::endl;
	std::cout << "PixelWidth " << PixelWidth << std::endl;
	std::cout << "PixelHeight " << PixelHeight << std::endl;
	std::cout << "MaxRGBChannel " << MaxRGBChannel << std::endl;
}

Procon32::GameData::GameData()
{

}

Procon32::GameData::~GameData()
{
}

std::string Procon32::GameData::MagicNumber;
int Procon32::GameData::Width;
int Procon32::GameData::Height;
int Procon32::GameData::SelectableTimes;
int Procon32::GameData::SelectiveRate;
int Procon32::GameData::ExchangeRate;
int Procon32::GameData::PixelWidth;
int Procon32::GameData::PixelHeight;
int Procon32::GameData::MaxRGBChannel;

int Procon32::GameData::POSTnum;