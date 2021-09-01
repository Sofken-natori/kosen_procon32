#pragma once
#include "KosenProcon32.hpp"

namespace Procon32 {

	class HTTPCommunication
	{
	private:

		//callback�֐�
		static size_t callbackWrite(char* ptr, size_t size, size_t nmemb, String* stream);

	public:

		void GetProblemData();
		void PostData();


		HTTPCommunication();
		~HTTPCommunication();


	};

}