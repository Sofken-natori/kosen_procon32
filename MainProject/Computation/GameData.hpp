#pragma once
#include"KosenProcon32.hpp"

namespace Procon32
{
	struct CommunicationData
	{
		std::string ProblemImagePath;
		std::string ProblemImageGUI;
		std::string RestoreImagePath;
		std::string AfterImagePath;
		std::string ProblemInfoPath;
		std::string GET_URL;
		std::string POST_URL;
		std::string Token;
	};

	class GameData
	{
	public:

		//void SetProblemInfo(std::string S1,std::string S2,int num);
		//std::string GetProblemInfo(int num);
		void ShowAll();

		static std::string MagicNumber;
		static int Width;
		static int Height;
		static int SelectableTimes;
		static int SelectiveRate;
		static int ExchangeRate;
		static int PixelWidth;
		static int PixelHeight;
		static int MaxRGBChannel;

		GameData();
		~GameData();
	};
}