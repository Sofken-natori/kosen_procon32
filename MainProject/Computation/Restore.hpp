#include"KosenProcon32.hpp"
#include"GameData.hpp"

namespace Procon32
{
	class Restore
	{
	private:

		CommunicationData comData;

	public:

		void RestoreImage();

		void ConversionImage(cv::Mat);

		Restore();
		~Restore();


	};
}