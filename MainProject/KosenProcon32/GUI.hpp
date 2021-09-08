#pragma once
#include"KosenProcon32.hpp"

namespace Procon32 {

	class GUI
	{
	private:

		//表示時に選別するための変数
		Font bigFont;
		Font smallFont;

		const String Game_Info1 = U"Time";
		const String Game_Info2 = U"Count";
		const String Game_Info3 = U"Result";

		//画像情報　翻訳あってるかわからん
		const String Image_Info1 = U"Magig Number";
		const String Image_Info2 = U"Segments";
		const String Image_Info3 = U"Selectable Times";
		const String Image_info4 = U"Rate";
		const String Image_info5 = U"Image Size";
		const String Image_info6 = U"Max RGB";

		

		Font test;

	public:

		void draw();

		//開催中の試合が変更されたとき
		//新規に試合が開始した際に初期データを生成したいので呼んであげてください
		void dataUpdate();

		GUI();
		~GUI();


	};
}