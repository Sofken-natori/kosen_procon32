#include"KosenProcon32.hpp"
#include"GameData.hpp"

namespace Procon32
{
	class Restore
	{
	private:

		CommunicationData comData;
		GameData data;

		//ífï–âÊëúÇÃècâ°ÇÃÉsÉNÉZÉãêî
		int piece_size;


		std::string S, s1, s2;

	public:

		void RestoreImage();

		void MakeImage(std::vector<std::vector<cv::Mat>>& frag2);

		void SWAP(std::vector<cv::Mat>& frag);

		void ROTATION(std::vector<cv::Mat>& frag);

		void RANDOM(std::vector<cv::Mat>& frag, std::vector<std::vector<cv::Mat>>& frag2);

		void RANDOM_SWAP(std::vector<cv::Mat>& frag, std::vector<std::vector<cv::Mat>>& frag2);

		void RANDOM_ROTATION(std::vector<cv::Mat>& frag, std::vector<std::vector<cv::Mat>>& frag2);

		void END();

		void ConversionImage(cv::Mat img);

		Restore();
		~Restore();


	};
}