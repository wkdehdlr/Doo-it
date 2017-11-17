//visited안쓰고 해결하는 방법이 있다!!
#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
#include<functional>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

struct now {
	int x;
	int y;
	int total;
};

bool operator<(now t, now u) {
	return t.total > u.total;
}


priority_queue<now> pq;

bool visited[101][101];
int arr[101][101];
int new_arr[101][101];
int t, N;
int min_dir;

void BFS();
int main()
{
	priority_queue<now> pq2;
	scanf("%d", &t);
	for (int tc = 0; tc < 10; tc++)
	{
		pq = pq2;
		memset(visited, false, sizeof(visited));
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%1d", &arr[i][j]);
			}
		}
		pq.push({ 1,1,0 });
		visited[1][1] = true;
		BFS();
		printf("#%d %d\n", tc + 1, min_dir);
	}
}
void BFS()
{
	while (!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int total = pq.top().total;
		pq.pop();

		if (x == N && y == N)
		{
			min_dir = total;
			return;
		}

		for (int k = 0; k < 4; k++)
		{
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 1 && r <= N&&c >= 1 && c <= N&&visited[r][c] == false)
			{
				visited[r][c] = true;
				pq.push({ r,c,arr[r][c] + total });
			}
		}
	}
}