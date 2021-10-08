#include"Restore.hpp"

void Procon32::Restore::RestoreImage()
{

	cv::Mat image = cv::imread(comData.ProblemImagePath);
	if (image.empty())
	{
		std::cerr << "ProblemImage could not be opened." << std::endl;
	}

	ConversionImage(image);

	std::vector<cv::Mat> pieces;
	std::vector<std::vector<cv::Mat>> pieces2(data.Height, std::vector<cv::Mat>(data.Width));

	//piecesにpushback
	for (int y = 0; y < data.Height; y++)
	{
		for (int x = 0; x < data.Width; x++)
		{
			pieces.push_back(image(cv::Rect(x * piece_size, y * piece_size, piece_size, piece_size)).clone());
		}
	}

	int count = 0;

	//pieces2にpushback
	for (int y = 0; y < data.Height; y++)
	{
		for (int x = 0; x < data.Width; x++)
		{

			pieces2.at(y).at(x) = pieces[count];

			count++;
		}
	}

	while (S != "END")
	{
		std::cout << "コマンドを入力してください" << std::endl;
		std::cin >> S;

		if (S == "SWAP")
		{
			SWAP(pieces);
		}
		else if (S == "ROTATION")
		{
			ROTATION(pieces);
		}
		else if (S == "RANDOM_SWAP")
		{
			RANDOM_SWAP(pieces, pieces2);
		}
		else if (S == "RANDOM_ROTATION")
		{
			RANDOM_ROTATION(pieces, pieces2);
		}
		else if (S == "RANDOM_ALL")
		{
			RANDOM(pieces, pieces2);
		}
		else if (S == "END")
		{
			break;
		}
		else
		{
			std::cout << "無効なコマンドです" << std::endl;
			std::cout << std::endl;
		}
	}

	MakeImage(pieces2);



	//END();
}

void Procon32::Restore::SWAP(std::vector<cv::Mat>& frag)
{
	std::cout << "SWAP:交換する断片画像を選択してください" << std::endl;
	std::cin >> s1 >> s2;
	
}

void Procon32::Restore::ROTATION(std::vector<cv::Mat>& frag)
{
	int Angle;
	std::cout << "ROTATION:回転する断片画像を選択してください" << std::endl;
	std::cin >> s1;
	std::cout << "どのくらい回転しますか？ " << "0:0 " << "1:90 " << "2:180 " << "3:270" << std::endl;
	std::cin >> Angle;



}

void Procon32::Restore::RANDOM(std::vector<cv::Mat>& frag, std::vector<std::vector<cv::Mat>>& frag2)
{
	RANDOM_SWAP(frag, frag2);
	RANDOM_ROTATION(frag, frag2);
}


void Procon32::Restore::RANDOM_SWAP(std::vector<cv::Mat>& frag, std::vector<std::vector<cv::Mat>>& frag2)
{
	std::random_device rnd_swap;
	std::mt19937 swap_engine(rnd_swap());
	std::shuffle(frag.begin(), frag.end(), swap_engine);

	int count = 0;

	for (int y = 0; y < data.Height; y++)
	{
		for (int x = 0; x < data.Width; x++)
		{

			frag2.at(y).at(x) = frag[count];

			count++;
		}
	}
}

void Procon32::Restore::RANDOM_ROTATION(std::vector<cv::Mat>& frag, std::vector<std::vector<cv::Mat>>& frag2)
{
	std::random_device rnd_rotation;
	std::mt19937 rotation_engine(rnd_rotation());
	std::uniform_int_distribution<> rand100(0, 3);

	int rand;

	for (int i = 0; i < frag.size(); i++)
	{
		cv::Mat A = frag[i];
		rand = rand100(rotation_engine);

		switch (rand)
		{
		case 0:
			break;
		case 1:
			cv::rotate(A, A, cv::ROTATE_90_CLOCKWISE);
			break;
		case 2:
			cv::rotate(A, A, cv::ROTATE_180);
			break;
		case 3:
			cv::rotate(A, A, cv::ROTATE_90_COUNTERCLOCKWISE);
			break;
		default:
			break;
		}
	}

	int count = 0;

	for (int y = 0; y < data.Height; y++)
	{
		for (int x = 0; x < data.Width; x++)
		{

			frag2.at(y).at(x) = frag[count];

			count++;
		}
	}
}

void Procon32::Restore::END()
{
	
}


void Procon32::Restore::MakeImage(std::vector<std::vector<cv::Mat>>& frag2)
{
	cv::Mat AAA = cv::Mat(data.Height, data.Width, CV_8UC3);

	for (int y = 0; y < data.Height; y++)
	{

		cv::Mat bbb = frag2.at(y).at(0);
		cv::Mat ccc;

		for (int x = 1; x < data.Width; x++)
		{
			ccc = frag2.at(y).at(x);
			cv::hconcat(bbb, ccc, bbb);
		}

		if (y == 0)
		{
			AAA = bbb.clone();
		}
		else
		{
			cv::vconcat(AAA, bbb, AAA);
		}
	}
	cv::imshow("AAA", AAA);
	cv::waitKey(0);
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