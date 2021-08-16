#pragma once

#include <Siv3D.hpp>
#include<condition_variable>
#include <future>
#include<random>

namespace Procon32 {

	//(2Å`16)
	const int32 YokoLength = 10;
	const int32 TateLength = 5;
	//(1Å`500)
	const int32 SelectCost = 25;
	//(1Å`100)
	const int32 TurnCost = 50;

}