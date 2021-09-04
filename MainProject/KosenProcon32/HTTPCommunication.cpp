#include"HTTPCommunication.hpp"

size_t Procon32::HTTPCommunication::callbackWrite(char* ptr, size_t size, size_t nmemb, String* stream) 
{
	
}


bool Procon32::HTTPCommunication::pingServerConnectionTest()
{

}

Procon32::HTTPCommunication::HTTPCommunication()
{

	{
		JSONReader reader(U"AccessInfo.json");
		comData.token = reader[U"Token"].getString();
		
	}

	//Setting Header
	postList = NULL;
	otherList = NULL;


	//Handle-initilize








}

Procon32::HTTPCommunication::~HTTPCommunication()
{

}