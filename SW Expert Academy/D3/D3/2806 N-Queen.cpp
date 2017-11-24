#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;


int dr[8] = { 0,-1,1,-1,0,1,1,1 };
int dc[8] = { -1,-1,0,1,1,1,0,-1 };
bool visited[11][11];
int arr[11][11];
int T, N;
int flag;
int cnt;
int total_cnt;
void DFS(int, int,int);
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		total_cnt = 0;
		scanf("%d", &N);
		for (int y = 1; y <= N; ++y)
		{
			memset(arr, 0, sizeof(int) * 11 * 11);
			memset(visited, false, sizeof(bool) * 11 * 11);
			//////////////////////////
			cnt = 0;
			for (int i = 1; i <= N; ++i)
			{
				for (int j = y; j <= N; ++j)
				{
					flag = 0;
					arr[i][j] = 1;
					DFS(i, j, 8);
					if (flag)
						arr[i][j] = 0;
					else
						cnt++;
				}
			}
			if (cnt == N)
				total_cnt++;
			//////////////////////////
		}
		printf("#%d %d\n", tc + 1, total_cnt);
	}
}
void DFS(int i, int j, int t)
{
	if (visited[i][j] && t == 8)
	{
		flag = 1;
		return;
	}
	else
	{
		if (t == 8)
		{
			visited[i][j] = true;
			for (int k = 0; k < 8; ++k)
			{
				int r = i + dr[k];
				int c = j + dc[k];
				if (r >= 1 && r <= N && c >= 1 && c <= N)
				{
					DFS(r, c, k);
				}
			}
		}
		else
		{
			visited[i][j] = true;
			int r = i + dr[t];
			int c = j + dc[t];
			if (r >= 1 && r <= N && c >= 1 && c <= N)
			{
				DFS(r, c, t);
			}
		}
	}
}