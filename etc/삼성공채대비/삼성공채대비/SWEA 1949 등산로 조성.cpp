#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
queue<info> q;
int arr[9][9];
bool visited[9][9];
int T, N, K;
int mx = 0, mxd = 0;
void DFS(int i, int j, int dir, int dep, bool ok)
{
	if (dep > mxd)
		mxd = dep;

	visited[i][j] = true;
	for (int k = 0; k < 4; ++k)
	{
		int r = i + dr[k];
		int c = j + dc[k];
		if (r >= 1 && r <= N && c >= 1 && c <= N && !visited[r][c])
		{
			if (arr[r][c] < arr[i][j])
			{
				DFS(r, c, dir, dep + 1, ok);
			}
			else
			{
				if (arr[r][c] - dir < arr[i][j] && ok) {
					arr[r][c] -= dir;
					DFS(r, c, dir, dep + 1, false);
					arr[r][c] += dir;
				}
			}
		}
	}
	visited[i][j] = false;	
}
void BFS()
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		visited[x][y] = true;
		for (int dir = 0; dir < 4; ++dir)
		{
			for (int k = 1; k <= K; ++k)
			{
				int r = x + dr[dir];
				int c = y + dc[dir];
				if (r >= 1 && r <= N && c >= 1 && c <= N && !visited[r][c])
				{
					if (arr[r][c] < arr[x][y])
					{
						DFS(r, c, k, 1,true);
					}
					else
					{
						if (arr[r][c] - k < arr[x][y]) {
							arr[r][c] -= k;
							DFS(r, c, k, 1,false);
							arr[r][c] += k;
						}
					}
				}
			}
		}
		visited[x][y] = false;
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		mx = 0; mxd = 0;
		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
			{
				scanf("%d", &arr[i][j]);
				if (mx < arr[i][j])
					mx = arr[i][j];
			}
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (arr[i][j] == mx)
					q.push({ i,j });

		BFS();
		printf("#%d %d\n", tc + 1, mxd + 1);
	}
}