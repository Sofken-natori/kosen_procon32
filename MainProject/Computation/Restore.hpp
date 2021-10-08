#include"KosenProcon32.hpp"
#include"GameData.hpp"

namespace Procon32
{
	class Restore
	{
	private:

		CommunicationData comData;
		GameData data;

		//�f�Љ摜�̏c���̃s�N�Z����
		int piece_size;

		std::string S;

	public:

		void RestoreImage();



		void ConversionImage(cv::Mat img);

		Restore();
		~Restore();


	};
}