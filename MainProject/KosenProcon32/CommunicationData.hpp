#pragma once
#include"KosenProcon32.hpp"

namespace Procon32 {
	enum class CommunicationState
	{
		Null,
		Done,
		Connecting,
	};

	struct CommunicationData
	{
		//token
		String token;

		//GET-URL
		String GEThost;

		//POST-URL
		String POSThost;

		//í êMåãâ 
		ConnectionStatusCode connectionCode;
	};
}