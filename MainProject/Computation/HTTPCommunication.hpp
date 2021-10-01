#pragma once
#include"KosenProcon32.hpp"
#include<string>

namespace Procon32 {

	class HTTPCommunication
	{
	private:

		CURL* curl;
		FILE* fp;
		CURLcode res;

		const char* GET_URL;
		const char* POST_URL;

	public:

		void GETProblem();

		void POSTAnswer();

		HTTPCommunication();
		~HTTPCommunication();
	};
}