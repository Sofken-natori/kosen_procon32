#include"Restore.hpp"

void Procon32::Restore::RestoreImage()
{
	//問題画像の読み取り
	cv::Mat image = cv::imread(comData.ProblemImagePath);
	if (image.empty())
	{
		std::cerr << "ProblemImage could not be opened." << std::endl;
	}

	ConversionImage(image);

	//グレイスケール化
	cv::Mat grayimage;
	cv::cvtColor(image, grayimage, cv::COLOR_RGB2GRAY);
	
	std::vector<cv::Mat> Unfinished_piece;

	//座標00の断片画像
	cv::Mat piece_00;

	//unfinishedpieceにpush 
	//注意！　座標00の断片画像はpushされません！
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

			//unpieceの四辺の中で合計値の最小値を求める 00の右辺との絶対値計算
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
		//U 上辺
		for (int x = 0; x < size; x++)
		{
			Total += img.at<unsigned char>(0, x);
		}

		return Total;
		break;
	case 1:
		//R 右辺
		for (int y = 0; y < size; y++)
		{
			Total += img.at<unsigned char>(y, size - 1);
		}

		return Total;
		break;
	case 2:
		//D 下辺
		for (int x = 0; x < size; x++)
		{
			Total += img.at<unsigned char>(size - 1, x);
		}

		return Total;
		break;
	case 3:
		//L 左辺
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





//GUI読み取り用に.ppm→.jpg変換　この関数は必要なのか?
void Procon32::Restore::ConversionImage(cv::Mat img)
{
	cv::imwrite(comData.ProblemImageGUI, img);
}






Procon32::Restore::Restore()
{
	// JSONデータの読み込み。
	std::ifstream ifs("Data/GameData.json", std::ios::in);
	if (ifs.fail()) {
		std::cerr << "failed to read GameData.json" << std::endl;
	}
	const std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	ifs.close();

	// JSONデータを解析する。
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