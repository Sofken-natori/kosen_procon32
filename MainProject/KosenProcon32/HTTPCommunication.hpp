#pragma once
#include"KosenProcon32.hpp"
#include"CommunicationData.hpp"

namespace Procon32 {

	class HTTPCommunication
	{
	private:

		CommunicationData comData;

		//callback�֐�
		static size_t callbackWrite(char* ptr, size_t size, size_t nmemb, String* stream);


	public:

		// ping - failed������v���O�����𗎂Ƃ��B
		bool pingServerConnectionTest();

		HTTPCommunication();
		~HTTPCommunication();
	};
}