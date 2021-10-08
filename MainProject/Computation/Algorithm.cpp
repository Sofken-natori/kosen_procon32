#include"Algorithm.hpp"

void Procon32::Algorithm::algorithm()
{
	int count = 0;

	for (int i = 0; i < N2; i++)
	{
		for (int j = 0; j < N2; j++)
		{
			MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
		}
	}

	//while (count <= data.SelectableTimes)
	//{

	//	count++;
	//}

	Puzzle in;

	for (int i = 0; i < N2; i++)
	{
		std::cin >> in.f[i];
		if (in.f[i] == 0)
		{
			in.f[i] = N2;
			in.space = i;
		}
	}
}

int Procon32::Algorithm::getAllMD(Puzzle pz)
{
	int sum = 0;
	for (int i = 0; i < N2; i++)
	{
		if (pz.f[i] == N2)continue;
		sum += MDT[i][pz.f[i] - 1];
	}
	return sum;
}

bool Procon32::Algorithm::dfs(int depth, int prev)
{
	if (state.MD == 0)
	{
		return true;
	}

	if (depth + state.MD > limit)
	{
		return false;
	}

	int sx = state.space / N;
	int sy = state.space % N;
	Puzzle tmp;

	for (int r = 0; r < 4; r++)
	{
		int tx = sx + dx[r];
		int ty = sy + dy[r];
		if (tx < 0 || ty < 0 || tx >= N || ty >= N)
		{
			continue;
		}
		if (max(prev, r) - min(prev, r) == 2)
		{
			continue;
		}

		tmp = state;

		state.MD -= MDT[tx * N + ty][state.f[tx * N + ty] - 1];
		state.MD += MDT[sx * N + sy][state.f[tx * N + ty] - 1];
		std::swap(state.f[tx * N + ty], state.f[sx * N + sy]);
		state.space = tx * N + ty;
		if (dfs(depth + 1, r)) { path[depth] = r; return true; }
		state = tmp;
	}

	return false;
}

std::string Procon32::Algorithm::iterative_deepening(Puzzle in)
{
	//初期状態のマンハッタン距離
	in.MD = getAllMD(in);

	for (limit = in.MD; limit <= LIMIT; limit++)
	{
		state = in;
		if (dfs(0, -100))
		{
			std::string ans = "";

			for (int i = 0; i < limit; i++)ans += dir[path[i]];
			return ans;
		}
	}

	return "unsolvable";
}


Procon32::Algorithm::Algorithm()
{
	ans = "";
	N = data.Height;
	N2 = data.Width * data.Height;
}

Procon32::Algorithm::~Algorithm()
{
}