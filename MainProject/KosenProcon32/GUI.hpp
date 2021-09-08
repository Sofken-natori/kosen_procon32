#pragma once
#include"KosenProcon32.hpp"

namespace Procon32 {

	class GUI
	{
	private:

		//�\�����ɑI�ʂ��邽�߂̕ϐ�
		Font bigFont;
		Font smallFont;

		const String Game_Info1 = U"Time";
		const String Game_Info2 = U"Count";
		const String Game_Info3 = U"Result";

		//�摜���@�|�󂠂��Ă邩�킩���
		const String Image_Info1 = U"Magig Number";
		const String Image_Info2 = U"Segments";
		const String Image_Info3 = U"Selectable Times";
		const String Image_info4 = U"Rate";
		const String Image_info5 = U"Image Size";
		const String Image_info6 = U"Max RGB";

		

		Font test;

	public:

		void draw();

		//�J�Ò��̎������ύX���ꂽ�Ƃ�
		//�V�K�Ɏ������J�n�����ۂɏ����f�[�^�𐶐��������̂ŌĂ�ł����Ă�������
		void dataUpdate();

		GUI();
		~GUI();


	};
}