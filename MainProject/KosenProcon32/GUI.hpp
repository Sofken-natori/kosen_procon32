#pragma once
#include"KosenProcon32.hpp"

namespace Procon32 {

	class GUI
	{
	private:

		//表示時に選別するための変数
		Font bigFont;
		Font smallFont;
		
		Texture ProblemImage;
		Texture RestoreImage;
		Texture AfterImage;

		


	public:

		void draw();

		//開催中の試合が変更されたとき
		//新規に試合が開始した際に初期データを生成したいので呼んであげてください
		void dataUpdate();

		GUI();
		~GUI();


	};
}