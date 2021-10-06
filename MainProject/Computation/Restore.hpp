#include"KosenProcon32.hpp"
#include"GameData.hpp"

namespace Procon32
{
	class Restore
	{
	private:
		
		int calculatioPixTotal(int direction, int size, cv::Mat img);

		CommunicationData comData;
		GameData data;

		//断片画像の縦横のピクセル数
		int piece_size;

		//座標00の四辺ピクセルの合計値
		int pix00_totalU;
		int pix00_totalR;
		int pix00_totalD;
		int pix00_totalL;

	public:

		void RestoreImage();



		void ConversionImage(cv::Mat img);

		Restore();
		~Restore();


	};
}