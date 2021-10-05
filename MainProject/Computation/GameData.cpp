#include"GameData.hpp"

//void Procon32::GameData::SetProblemInfo(std::string s1,std::string s2,int num)
//{
//	switch (num)
//	{
//	case 0:
//		MagicNumber = s1;
//		break;
//	case 1:
//
//		Width = stoi(s1);
//		Height = stoi(s2);
//
//		break;
//	case 2:
//
//		SelectableTimes = stoi(s1);
//		break;
//	case 3:
//
//		SelectiveRate = stoi(s1);
//		ExchangeRate = stoi(s2);
//
//		break;
//	case 4:
//
//		PixelWidth = stoi(s1);
//		PixelHeight = stoi(s2);
//
//		break;
//	case 5:
//
//		MaxRGBChannel = stoi(s1);
//		break;
//
//	default:
//		break;
//	}
//}

//std::string Procon32::GameData::GetProblemInfo(int num)
//{
//	std::string A, B, C;
//
//	switch (num)
//	{
//	case 0:
//		return MagicNumber;
//		break;
//	case 1:
//		A = std::to_string(Width);
//		B = std::to_string(Height);
//		C = A + " " + B;
//		return C;
//		break;
//	case 2:
//		C = std::to_string(SelectableTimes);
//		return C;
//		break;
//	case 3:
//		A = std::to_string(SelectiveRate);
//		B = std::to_string(ExchangeRate);
//		C = A + " " + B;
//		return C;
//		break;
//	case 4:
//		A = std::to_string(PixelWidth);
//		B = std::to_string(PixelHeight);
//		C = A + " " + B;
//		return C;
//		break;
//	case 5:
//		C = std::to_string(MaxRGBChannel);
//		return C;
//		break;
//
//	default:
//		break;
//	}
//}

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