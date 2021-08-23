#pragma once
#include"KosenProcon32.hpp"

namespace Procon32 {
	
	class Generator
	{
	private:

		Array<String>origin = { U"0",U"1",U"2",U"3",U"4",U"5",U"6",U"7",U"8",U"9",U"a",U"b",U"c",U"d",U"e",U"f" };

	public:


		Array<Array<String>>MotoZahyou;
		Array<Array<String>>Zahyou;
		Array<Array<int>>Kaitenn;

	

		void generating();

		Generator();
		~Generator();
	};
}