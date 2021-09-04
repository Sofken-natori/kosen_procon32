#pragma once
#include<Siv3D.hpp>
#include<opencv2/opencv.hpp>
#include<curl/curl.h>
#include<mutex>
#include<condition_variable>
#include<future>

namespace Procon32 {


	enum class ConnectionStatusCode : uint32 
	{
		//���ł��Ȃ����
		Null,

		//Code:200,201(post)
		//����
		OK,

		//Code:400
		//�����̊J�n�O�ɃA�N�Z�X�����ꍇ
		//UnixTime�����Ă���̂ŗv�m�F
		TooEarly,

		//Code:400
		//�Q�����Ă��Ȃ������ɑ΂��郊�N�G�X�g
		//�[���ȃG���[�A�����I���������߂���B
		InvailedMatches,

		//curl_easy_perform() is failed.
		//���Ԃ�I�������^�C���A�E�g�A�đ����ĘA������悤�������狭���I���������߂���B
		ConnectionLost,

		//Unknown Error
		//Code��200,201,400,401�ȊO�̎�
		//����o���炾�������󂯎����json�ɂȂ񂩂��珑���Ă���
		//json/buffer.json��ǂ�
		//�[���ȃG���[�A�����I���������߂���B
		UnknownError

	};

	template <class... Args, std::enable_if_t<s3d::detail::format_validation<Args...>::value>* = nullptr>
	inline void SafeConsole(const Args & ... args) {
		static std::mutex consoleMtx;
		std::lock_guard<std::mutex> lock(consoleMtx);
		Console << Format(args...);
	}
}