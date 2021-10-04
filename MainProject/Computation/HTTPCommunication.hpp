#pragma once
#include"KosenProcon32.hpp"
#include"GameData.hpp"

namespace Procon32 {

	class HTTPCommunication
	{
	private:

		CommunicationData comData;

		CURL* curl;
		FILE* fp;
		CURLcode res;

		const char* GET_URL;
		const char* POST_URL;

		struct curl_slist* postList = NULL;

		
	public:

		void GETProblem();

		void POSTAnswer();

		HTTPCommunication();
		~HTTPCommunication();
	};
}