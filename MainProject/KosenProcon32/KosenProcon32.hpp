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

	enum class ConnectionStatusCode : uint32 {
		//�Ȃ�ł��Ȃ����
		Null,

		//����
		OK,

		//�����J�n�O�ɃA�N�Z�X�����ꍇ
		TooEarly,

		//�Q�����Ă��Ȃ������ɑ΂��郊�N�G�X�g
		//�[���ȃG���[�A�����I���������߂���B
		InvailedMatches,

		//�g�[�N�����Ԉ���Ă���������͑��݂��Ȃ��ꍇ
		//�[���ȃG���[�A�����I���������߂���B
		InVailedToken,

		//curl_easy_perform() is failed.
		//���Ԃ�I�������^�C���A�E�g�A�đ����ĘA������悤�������狭���I���������߂���B
		ConnectionLost,

		//�[���ȃG���[�A�����I���������߂���B
		Unknownerror
	};

}