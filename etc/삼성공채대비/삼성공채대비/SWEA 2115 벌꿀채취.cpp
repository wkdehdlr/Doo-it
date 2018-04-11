#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;

struct info {
	int num, x, y;
};
bool operator<(info f, info g)
{
	return f.num < g.num;
}
priority_queue<info> pq;
int arr[11][11];
int T, N, M, C;
void DFS(int i, int j, int tot, int prc, int limt)
{
	if (j > limt)
	{
		pq.push({ prc, i ,j - 1 });
	}
	else
	{
		for (; j <= limt; ++j)
		{
			if (tot + arr[i][j] <= C)
				DFS(i, j + 1, tot + arr[i][j], prc + (arr[i][j] * arr[i][j]), limt);
			else
				DFS(i, j + 1, tot , prc , limt);
		}
	}
}

int func()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N - M + 1; ++j)
		{
			DFS(i, j, 0, 0, j + M - 1);
		}
	}

	int res1 = pq.top().num, res2 = 0;
	int x1 = pq.top().x;
	int y1 = pq.top().y;
	int x2, y2;
	pq.pop();
	do
	{
		res2 = pq.top().num;
		x2 = pq.top().x;
		y2 = pq.top().y;
		pq.pop();

	} while (x1 == x2 && abs(y1 - y2) < M);

	while (!pq.empty())pq.pop();
	return res1 + res2;
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d %d %d", &N, &M, &C);
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				scanf("%d", &arr[i][j]);

		printf("#%d %d\n", tc + 1, func());
	}
}