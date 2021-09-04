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

		//�n���h��
		CURL* pingHandle;
		CURL* matchesInfoHandle;
		Array<CURL*> getMatchHandles;
		Array<CURL*> postActionHandles;

		//Header��list
		curl_slist* postList = NULL;
		curl_slist* otherList = NULL;

		//Post�f�[�^�ێ��p
		std::string tempPostString;

	public:



		

		// ping - failed������v���O�����𗎂Ƃ��B
		bool pingServerConnectionTest();

		bool checkPostAction();

		HTTPCommunication();
		~HTTPCommunication();
	};
}