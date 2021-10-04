#pragma once
#include"KosenProcon32.hpp"
#include<string>

namespace Procon32 {

	class HTTPCommunication
	{
	private:

		CURL* curl;
		FILE* fp;
		FILE* fp2;
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