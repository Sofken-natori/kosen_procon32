#pragma once
#include"KosenProcon32.hpp"

namespace Procon32 {


	class Generator
	{
	private:

		std::array<std::string,16> origin = { "0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f" };
		
		std::vector<std::pair<int, int>>p;
		
		int count;

	public:
		
		void Generate();

		std::vector<std::vector<std::string>> moto;
		std::vector<std::vector<std::string>> zahyou;
		std::vector<std::vector<std::string>>kaitenn;

		Generator();
		~Generator();
		
	};
}