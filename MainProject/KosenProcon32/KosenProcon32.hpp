#pragma once

#include <Siv3D.hpp>
#include<opencv2/opencv.hpp>
#include<curl/curl.h>
#include<condition_variable>
#include <future>
#include<random>

namespace Procon32 {

	//(2～16)
	constexpr int32 YokoLength = 10;
	constexpr int32 TateLength = 5;
	//(1～500)
	constexpr int32 SelectCost = 25;
	//(1～100)
	constexpr int32 TurnCost = 50;

	enum class ConnectionStatusCode : uint32 {
		//なんでもない状態
		Null,

		//正常
		OK,

		//試合開始前にアクセスした場合
		TooEarly,

		//参加していない試合に対するリクエスト
		//深刻なエラー、強制終了をお勧めする。
		InvailedMatches,

		//トークンが間違っているもしくは存在しない場合
		//深刻なエラー、強制終了をお勧めする。
		InVailedToken,

		//curl_easy_perform() is failed.
		//たぶん鯖落ちかタイムアウト、再送して連続するようだったら強制終了をお勧めする。
		ConnectionLost,

		//深刻なエラー、強制終了をお勧めする。
		Unknownerror
	};

}