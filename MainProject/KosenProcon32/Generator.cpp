#include"Generator.hpp"

//アルゴリズム開発用に座標や回転情報を配列に記録します
//分割数を変えるときはKosenProcon32.hppの値を変更してください

void Procon32::Generator::Generate()
{
	for (int i = 0; i < TateLength; i++) {
		for (int j = 0; j < YokoLength; j++) {
			p.emplace_back(i, j);
		}
	}

	std::random_device seed_gen;
	std::mt19937 engine1(seed_gen());
	std::shuffle(p.begin(), p.end(), engine1);

	for (int i = 0; i < TateLength; i++) {
		for (int j = 0; j < YokoLength; j++) {
			moto[i][j] = origin[j] + origin[i];
		}

		moto[i][YokoLength - 1] = origin[YokoLength - 1] + origin[i];
	}
	
	//座標情報の記録
	for (int i = 0; i < TateLength; i++) {
		for (int j = 0; j < YokoLength; j++) {
			count++;
			zahyou[i][j] = moto[p[count].first][p[count].second];
		}
	}

	std::random_device rd;
	std::default_random_engine engine2(rd());
	std::uniform_int_distribution<int> distr(0, 3);

	//回転情報の記録
	for (int i = 0; i < TateLength; i++) {
		for (int j = 0; j < YokoLength; j++) {
			kaitenn[i][j] = distr(engine2);
		}
	}

	
	std::shuffle(kaitenn.begin(), kaitenn.end(), engine1);
}

Procon32::Generator::Generator()
{
	count = -1;
}

Procon32::Generator::~Generator()
{
}