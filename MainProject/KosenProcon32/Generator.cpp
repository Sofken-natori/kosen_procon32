#include"Generator.hpp"

void Procon32::Generator::generating()
{
	std::vector<std::pair<int, int>>p;
	for (int i = 0; i < TateLength; i++) {
		for (int j = 0; j < YokoLength; j++) {
			p.emplace_back(i, j);
		}
	}

	//pのシャッフル
	std::random_device seed_gen;
	std::mt19937 engine1(seed_gen());
	std::shuffle(p.begin(), p.end(), engine1);

	////MotoZahyouに書き込み
	//for (int i = 0; i < TateLength; i++) {
	//	for (int j = 0; j < YokoLength; j++) {
	//		MotoZahyou[i][j] = origin[j] + origin[i];
	//	}
	//}

	////zahyouに書き込み
	//int count = -1;
	//for (int i = 0; i < TateLength; i++) {
	//	for (int j = 0; j < YokoLength; j++) {
	//		count++;
	//		Zahyou[i][j] = MotoZahyou[p[count].first][p[count].second];
	//	}
	//}

	////回転情報用の乱数生成器
	//std::random_device rd;
	//std::default_random_engine engine2(rd());
	//std::uniform_int_distribution<int> distr(0, 3);

	////kaitennに書き込み
	//for (int i = 0; i < TateLength; i++) {
	//	for (int j = 0; j < YokoLength; j++) {
	//		Kaitenn[i][j] = distr(engine2);
	//	}
	//}
	////kaitennのシャッフル
	//std::shuffle(Kaitenn.begin(), Kaitenn.end(), engine1);
}

Procon32::Generator::Generator()
{
	

}

Procon32::Generator::~Generator()
{
}