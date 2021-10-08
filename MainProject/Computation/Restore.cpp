#include"Restore.hpp"

void Procon32::Restore::RestoreImage()
{
	//���摜�̓ǂݎ��
	cv::Mat image = cv::imread(comData.ProblemImagePath);
	if (image.empty())
	{
		std::cerr << "ProblemImage could not be opened." << std::endl;
	}

	ConversionImage(image);

	//�O���C�X�P�[����
	cv::Mat grayimage;
	cv::cvtColor(image, grayimage, cv::COLOR_RGB2GRAY);
	
	std::vector<cv::Mat> Unfinished_piece;

	//���W00�̒f�Љ摜
	cv::Mat piece_00;

	//unfinishedpiece��push 
	//���ӁI�@���W00�̒f�Љ摜��push����܂���I
	for (int y = 0; y < data.Height; y++)
	{
		for (int x = 0; x < data.Width; x++)
		{
			if (y == 0 && x == 0)
			{
				piece_00 = grayimage(cv::Rect(x, y, piece_size, piece_size)).clone();
			}
			else
			{
				Unfinished_piece.push_back(grayimage(cv::Rect(x * piece_size, y * piece_size, piece_size, piece_size)).clone());
			}
		}
	}

	pix00_totalU = calculatioPixTotal(0, piece_size, grayimage);
	pix00_totalR = calculatioPixTotal(1, piece_size, grayimage);
	pix00_totalD = calculatioPixTotal(2, piece_size, grayimage);
	pix00_totalL = calculatioPixTotal(3, piece_size, grayimage);




	cv::Mat RestoreImage = piece_00.clone();
	cv::Mat unpiece, result;
	int MinTotal = 100000000, count = 0;
	while (true)
	{
		for (int i = count; i < Unfinished_piece.size(); i++)
		{
			std::cout << i << " " << count << std::endl;
			unpiece = Unfinished_piece[i];

			int Min = 1000000000, sum;

			//unpiece�̎l�ӂ̒��ō��v�l�̍ŏ��l�����߂� 00�̉E�ӂƂ̐�Βl�v�Z
			for (int rotate = 0; rotate < 4; rotate++)
			{
				sum = abs(pix00_totalR - calculatioPixTotal(rotate, piece_size, unpiece));
				Min = min(Min, sum);
				std::cout << "count " << count << " sum " << sum << " calculation " << calculatioPixTotal(rotate, piece_size, unpiece) << " Min " << Min << std::endl;
			}
			
			if (Min < MinTotal)
			{
				MinTotal = Min;
				result = unpiece;
			}
		}

		count++;
	}


	cv::hconcat(RestoreImage, result, RestoreImage);
	cv::imshow("Restore", RestoreImage);
	cv::waitKey(0);


	return;
}

int Procon32::Restore::calculatioPixTotal(int direction,int size, cv::Mat img)
{
	int Total = 0;
	switch (direction)
	{
	case 0:
		//U ���
		for (int x = 0; x < size; x++)
		{
			Total += img.at<unsigned char>(0, x);
		}

		return Total;
		break;
	case 1:
		//R �E��
		for (int y = 0; y < size; y++)
		{
			Total += img.at<unsigned char>(y, size - 1);
		}

		return Total;
		break;
	case 2:
		//D ����
		for (int x = 0; x < size; x++)
		{
			Total += img.at<unsigned char>(size - 1, x);
		}

		return Total;
		break;
	case 3:
		//L ����
		for (int y = 0; y < size; y++)
		{
			Total += img.at<unsigned char>(y, 0);
		}

		return Total;
		break;
	default:
		break;
	}
}





//GUI�ǂݎ��p��.ppm��.jpg�ϊ��@���̊֐��͕K�v�Ȃ̂�?
void Procon32::Restore::ConversionImage(cv::Mat img)
{
	cv::imwrite(comData.ProblemImageGUI, img);
}






Procon32::Restore::Restore()
{
	// JSON�f�[�^�̓ǂݍ��݁B
	std::ifstream ifs("Data/GameData.json", std::ios::in);
	if (ifs.fail()) {
		std::cerr << "failed to read GameData.json" << std::endl;
	}
	const std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	ifs.close();

	// JSON�f�[�^����͂���B
	picojson::value v;
	const std::string err = picojson::parse(v, json);
	if (err.empty() == false) {
		std::cerr << err << std::endl;
	}

	picojson::object& obj = v.get<picojson::object>();
	comData.ProblemImagePath = obj["ProblemImagePath"].get<std::string>();
	comData.ProblemImageGUI = obj["ProblemImage-GUI"].get<std::string>();

	piece_size = data.PixelWidth / data.Width;
}




Procon32::Restore::~Restore()
{
}