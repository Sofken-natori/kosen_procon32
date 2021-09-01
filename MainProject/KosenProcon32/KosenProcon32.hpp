#pragma once
#include<Siv3D.hpp>
#include<opencv2/opencv.hpp>
#include<curl/curl.h>

namespace Procon32 {


	enum class ConnectionStatusCode : uint32 
	{
		//何でもない状態
		Null,

		//Code:200,201(post)
		//正常
		OK,

		//Code:400
		//試合の開始前にアクセスした場合
		//UnixTimeも来ているので要確認
		TooEarly,

		//Code:400
		//参加していない試合に対するリクエスト
		//深刻なエラー、強制終了をお勧めする。
		InvailedMatches,

		//curl_easy_perform() is failed.
		//たぶん鯖落ちかタイムアウト、再送して連続するようだったら強制終了をお勧めする。
		ConnectionLost,

		//Unknown Error
		//Codeが200,201,400,401以外の時
		//これ出たらだいたい受け取ったjsonになんかしら書いてある
		//json/buffer.jsonを読め
		//深刻なエラー、強制終了をお勧めする。
		UnknownError

	};






}