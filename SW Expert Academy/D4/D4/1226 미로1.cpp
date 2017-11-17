#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

bool visited[101][101];
int arr[101][101];
int N;
int x, y;
bool flag;

void DFS(int, int);
int main()
{
	for (int tc = 0; tc < 10; tc++)
	{
		memset(visited, false, sizeof(visited));
		flag = false;
		scanf("%d", &N);
		for (int i = 1; i <= 100; ++i)
		{
			for (int j = 1; j <= 100; ++j)
			{
				scanf("%1d", &arr[i][j]);
				if (arr[i][j] == 2)
				{
					x = i; y = j;
				}
			}
		}

		DFS(x, y);
		if (flag == true)
			printf("#%d 1\n", tc + 1);
		else
			printf("#%d 0\n", tc + 1);
	}
}
void DFS(int i, int j)
{
	if (arr[i][j] == 3)
	{
		flag = true;
	}
	else
	{
		visited[i][j] = true;
		for (int k = 0; k < 4; ++k)
		{
			int r = i + dr[k];
			int c = j + dc[k];
			if (r >= 1 && r <= 100 && c >= 1 && c <= 100 && visited[r][c] == false && arr[r][c] != 1)
			{
				DFS(r, c);
				if (flag == true)
					return;
			}
		}
		visited[i][j] = false;
	}
}