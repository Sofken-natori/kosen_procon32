#pragma once
#include"KosenProcon32.hpp"

namespace Procon32 {
	
	class Generator
	{
	private:

	public:


		std::vector<std::vector<String>>moto;
		std::vector<std::vector<String>>zahyou;
		std::vector<std::vector<int>>kaitenn;


		void generate();




		Generator();
		~Generator();
	};
}