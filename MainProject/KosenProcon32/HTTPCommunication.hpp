#pragma once
#include"KosenProcon32.hpp"
#include"CommunicationData.hpp"

namespace Procon32 {

	class HTTPCommunication
	{
	private:

		CommunicationData comData;

		//callbackŠÖ”
		static size_t callbackWrite(char* ptr, size_t size, size_t nmemb, String* stream);


	public:

		// ping - failed‚µ‚½‚çƒvƒƒOƒ‰ƒ€‚ğ—‚Æ‚·B
		bool pingServerConnectionTest();

		HTTPCommunication();
		~HTTPCommunication();
	};
}