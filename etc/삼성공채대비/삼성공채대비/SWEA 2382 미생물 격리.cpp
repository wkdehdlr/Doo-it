#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
//(»ó: 1, ÇÏ : 2, ÁÂ : 3, ¿ì : 4)
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,-1,1 };
struct info {
	int x, y, cnt, dir;
};
struct cell {
	int tot, mxd, mxc;
};
queue<info> q;
int T, N, M, K;
int tm = 0;
int tot = 0;
int move()
{
	vector<vector<cell> > vec(100, vector<cell>(100));
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int dir = q.front().dir;
		q.pop();

		int r = x + dr[dir];
		int c = y + dc[dir];
		if (r == 0 || r == N - 1 || c == 0 || c == N - 1)//»¡°£º®¿¡ ¸¸³µÀ»¶§
		{
			vec[r][c].tot = cnt / 2;
			vec[r][c].mxd = (dir == 1 || dir == 2) ? 3 - dir : 7 - dir;
		}
		else
		{
			vec[r][c].tot += cnt;
			if (vec[r][c].mxc < cnt) {
				vec[r][c].mxc = cnt;
				vec[r][c].mxd = dir;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (vec[i][j].tot) {
				res += vec[i][j].tot;
				q.push({ i,j,vec[i][j].tot,vec[i][j].mxd });
			}

	return res;
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		tm = 0; tot = 0;
		scanf("%d %d %d", &N, &M, &K);
		for (int k = 0; k < K; ++k)
		{
			int x, y, cnt, dir;
			scanf("%d %d %d %d", &x, &y, &cnt, &dir);
			q.push({ x,y,cnt,dir });
		}
		while (tm < M)
		{
			tot = move();
			tm++;
		}
		while (!q.empty())q.pop();
		printf("#%d %d\n", tc + 1, tot);
	}
}