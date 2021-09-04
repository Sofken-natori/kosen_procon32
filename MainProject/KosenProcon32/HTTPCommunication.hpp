#pragma once
#include"KosenProcon32.hpp"
#include"CommunicationData.hpp"

namespace Procon32 {

	class HTTPCommunication
	{
	private:

		CommunicationData comData;

		//callback関数
		static size_t callbackWrite(char* ptr, size_t size, size_t nmemb, String* stream);

		//ハンドル
		CURL* pingHandle;
		CURL* matchesInfoHandle;
		Array<CURL*> getMatchHandles;
		Array<CURL*> postActionHandles;

		//Headerのlist
		curl_slist* postList = NULL;
		curl_slist* otherList = NULL;

		//Postデータ保持用
		std::string tempPostString;

	public:



		

		// ping - failedしたらプログラムを落とす。
		bool pingServerConnectionTest();

		bool checkPostAction();

		HTTPCommunication();
		~HTTPCommunication();
	};
}