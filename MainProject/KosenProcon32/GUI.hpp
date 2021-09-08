#pragma once
#include"KosenProcon32.hpp"

namespace Procon32 {

	class GUI
	{
	private:

		//�\�����ɑI�ʂ��邽�߂̕ϐ�
		Font bigFont;
		Font smallFont;
		
		Texture ProblemImage;
		Texture RestoreImage;
		Texture AfterImage;

		


	public:

		void draw();

		//�J�Ò��̎������ύX���ꂽ�Ƃ�
		//�V�K�Ɏ������J�n�����ۂɏ����f�[�^�𐶐��������̂ŌĂ�ł����Ă�������
		void dataUpdate();

		GUI();
		~GUI();


	};
}