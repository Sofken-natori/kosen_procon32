#pragma once

#include <Siv3D.hpp>
#include<opencv2/opencv.hpp>
#include<curl/curl.h>
#include<condition_variable>
#include <future>
#include<random>

namespace Procon32 {

	//(2�`16)
	constexpr int32 YokoLength = 10;
	constexpr int32 TateLength = 5;
	//(1�`500)
	constexpr int32 SelectCost = 25;
	//(1�`100)
	constexpr int32 TurnCost = 50;



}