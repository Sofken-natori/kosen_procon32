#pragma once
#include "KosenProcon32.hpp"

namespace Procon32 {

	class GUI
	{
	private:


		Font bigFont;
		Font smallFont;
		Font testFont;

	public:

		void draw();

		//�J�Ò��̎������ύX���ꂽ�Ƃ�
		//�V�K�Ɏ������J�n�����ۂɏ����f�[�^�𐶐��������̂ŌĂ�ł����Ă�������
		void dataUpdate();

		GUI();
		~GUI();
	};
}