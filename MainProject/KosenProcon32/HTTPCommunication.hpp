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


	public:

		// ping - failedしたらプログラムを落とす。
		bool pingServerConnectionTest();

		HTTPCommunication();
		~HTTPCommunication();
	};
}