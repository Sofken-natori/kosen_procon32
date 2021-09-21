#pragma once
//↓これで警告無視　ないとGETImageFileのfopenでエラー
#pragma warning(disable: 4996)
#include"KosenProcon32.hpp"
#include"CommunicationData.hpp"

namespace Procon32 {

	class HTTPCommunication
	{
	private:

		CommunicationData comData;

		CURL* curl;
		FILE* fp;
		CURLcode res;

		const char* URL;

	public:

		void GETProblemImage();



		HTTPCommunication();
		~HTTPCommunication();
	};
}