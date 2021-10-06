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

		//�f�Љ摜�̏c���̃s�N�Z����
		int piece_size;

		//���W00�̎l�Ӄs�N�Z���̍��v�l
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