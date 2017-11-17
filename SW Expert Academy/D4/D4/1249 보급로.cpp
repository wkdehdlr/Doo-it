#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

struct now {
	int x;
	int y;
};
now n = { 1,1};
queue<now> q;

//bool visited[101][101];
int arr[101][101];
int new_arr[101][101];
int t,N;
//int min_res;

void BFS();
int main()
{
	queue<now> q2;
	scanf("%d", &t);
	for (int tc = 0; tc < 1; tc++)
	{
		q = q2;
		memset(new_arr, 0, sizeof(new_arr));
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%1d", &arr[i][j]);
			}
		}
		q.push(n);
		BFS();
		printf("#%d %d\n", tc + 1, new_arr[N][N]);
	}
}
void BFS()
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 1 && r <= N&&c >= 1 && c <= N)
			{
				if (new_arr[r][c] == 0)
				{
					new_arr[r][c] = arr[r][c] + new_arr[x][y];
					q.push({ r,c });
				}
				else
				{
					if (new_arr[r][c] > arr[r][c] + new_arr[x][y])
					{
						new_arr[r][c] = arr[r][c] + new_arr[x][y];
						q.push({ r,c });
					}
				}
			}
		}
	}
}