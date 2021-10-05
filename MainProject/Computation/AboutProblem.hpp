#pragma once
#include"KosenProcon32.hpp"
#include"GameData.hpp"

namespace Procon32
{
	class AboutProblem
	{
	private:

		CommunicationData comData;

	public:

		void GETProblemInfo();

		void WRITEProblemInfo();

		AboutProblem();
		~AboutProblem();
	};
}