#pragma once
#include"KosenProcon32.hpp"
#include"GameData.hpp"

namespace Procon32 {

	class HTTPCommunication
	{
	private:

		CommunicationData comData;
		GameData data;

		CURL* curl;
		FILE* fp;
		CURLcode res;

		struct curl_slist* postList = NULL;

		
	public:

		void GETProblem();

		void POSTAnswer();

		HTTPCommunication();
		~HTTPCommunication();
	};
}