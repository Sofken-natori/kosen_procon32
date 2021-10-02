#pragma once
#include"KosenProcon32.hpp"

namespace Procon32
{
	class GameData
	{
	private:

		static std::string MagicNumber;
		static int Width;
		static int Height;
		static int SelectableTimes;
		static int SelectiveRate;
		static int ExchangeRate;
		static int PixelWidth;
		static int PixelHeight;
		static int MaxRGBChannel;

	public:

		void Set(std::string S1,std::string S2,int num);
		void ShowAll();

		GameData();
		~GameData();
	};
}