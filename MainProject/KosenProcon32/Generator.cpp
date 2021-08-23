#include"Generator.hpp"

void Procon32::Generator::generating()
{
	std::vector<std::pair<int, int>>p;
	for (int i = 0; i < TateLength; i++) {
		for (int j = 0; j < YokoLength; j++) {
			p.emplace_back(i, j);
		}
	}

	//p�̃V���b�t��
	std::random_device seed_gen;
	std::mt19937 engine1(seed_gen());
	std::shuffle(p.begin(), p.end(), engine1);

	////MotoZahyou�ɏ�������
	//for (int i = 0; i < TateLength; i++) {
	//	for (int j = 0; j < YokoLength; j++) {
	//		MotoZahyou[i][j] = origin[j] + origin[i];
	//	}
	//}

	////zahyou�ɏ�������
	//int count = -1;
	//for (int i = 0; i < TateLength; i++) {
	//	for (int j = 0; j < YokoLength; j++) {
	//		count++;
	//		Zahyou[i][j] = MotoZahyou[p[count].first][p[count].second];
	//	}
	//}

	////��]���p�̗���������
	//std::random_device rd;
	//std::default_random_engine engine2(rd());
	//std::uniform_int_distribution<int> distr(0, 3);

	////kaitenn�ɏ�������
	//for (int i = 0; i < TateLength; i++) {
	//	for (int j = 0; j < YokoLength; j++) {
	//		Kaitenn[i][j] = distr(engine2);
	//	}
	//}
	////kaitenn�̃V���b�t��
	//std::shuffle(Kaitenn.begin(), Kaitenn.end(), engine1);
}

Procon32::Generator::Generator()
{
	

}

Procon32::Generator::~Generator()
{
}