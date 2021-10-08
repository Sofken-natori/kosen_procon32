#include"KosenProcon32.hpp"
#include"GameData.hpp"

namespace Procon32
{
	class Algorithm
	{
	private:

		GameData data;

		int N;
		int N2;
		int limit;
		static const int LIMIT = 100;
		int path[LIMIT];

		const int dx[4] = { 0,-1,0,1 };
		const int dy[4] = { 1,0,-1,0 };
		const char dir[4] = { 'R','U','L','D' };


		struct Puzzle
		{
			int f[256],
				space,
				MD;
		};

		Puzzle state;

		int MDT[256][256];

	public:

		std::string ans;

		void algorithm();

		int getAllMD(Puzzle pz);

		bool dfs(int depth, int prev);

		std::string iterative_deepening(Puzzle pz);

		Algorithm();
		~Algorithm();

	};
}