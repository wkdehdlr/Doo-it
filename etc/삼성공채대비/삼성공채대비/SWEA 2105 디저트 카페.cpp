#pragma warning(disable : 4996)
#include<cstdio>

int dr[4] = { 1,1,-1,-1 };
int dc[4] = { 1,-1,-1,1 };
bool kind[101];
int arr[21][21];
int T, N;
int x, y;
int mx = 0;
void DFS(int i, int j, int dir, int cnt)
{
	if (x == i && y == j)
	{
		if (cnt > mx)
			mx = cnt;
	}
	else if (kind[arr[i][j]])
	{
		 return;
	}
	else
	{
		kind[arr[i][j]] = true;
		if (dir == 3) {
			if (i + dr[dir] >= 1 && i + dr[dir] <= N && j + dc[dir] >= 1 && j + dc[dir] <= N)
				DFS(i + dr[dir], j + dc[dir], dir, cnt + 1);
		}
		else {
			if (i + dr[dir] >= 1 && i + dr[dir] <= N && j + dc[dir] >= 1 && j + dc[dir] <= N)
				DFS(i + dr[dir], j + dc[dir], dir, cnt + 1);
			if (i + dr[(dir + 1) % 4] >= 1 && i + dr[(dir + 1) % 4] <= N && j + dc[(dir + 1) % 4] >= 1 && j + dc[(dir + 1) % 4] <= N)
				DFS(i + dr[(dir + 1) % 4], j + dc[(dir + 1) % 4], (dir + 1) % 4, cnt + 1);
		}
		kind[arr[i][j]] = false;
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		mx = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				scanf("%d", &arr[i][j]);


		for (int i = 1; i <= N - 2; ++i)
		{
			for (int j = 2; j <= N - 1; ++j)
			{
				x = i; y = j;
				kind[arr[i][j]] = true;
				DFS(i + dr[0], j + dc[0], 0, 1);
				kind[arr[i][j]] = false;
			}
		}

		printf("#%d %d\n", tc + 1, mx == 0 ? -1 : mx);
	}
}