#pragma warning(disable:4996)
#include<cstdio>
#include<deque>
using namespace std;

struct core {
	int type;
	int sum;
	int dir[4];
};
deque<core> de_temp;
deque<core> de;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
core arr[13][13];
bool visited[13][13];
int T, N, cnt;
int r1, c1;

void check_core2();
void link_start();
void DFS(int, int, int, int);
void check_core();
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%d", &arr[i][j].type);
				arr[i][j].sum = 0;
			}
		}
		check_core2(1,1);
		//check_core();
		//link_start();
	}
}
void check_core2(int r,int c)
{
	for (int i = r; i <= N; ++i)
	{
		for (int j = c; j <= N; ++j)
		{
			if (arr[i][j].type == 1)//코어면
			{
				visited[i][j] = true;
				if (!(i == 1 || i == N || j == 1 || j == N))//가장자리에있는 코어가 아니면
				{
					r1 = i; c1 = j;
					for (int k = 0; k < 4; ++k)
					{
						DFS2(i, j, k, 0);
					}
					return;
				}
			}
		}
	}
}
void DFS2(int i, int j, int k, int num)
{
	if (i == 1 || i == N || j == 1 || j == N)
	{
		cnt++; 
		check_core2(r1, c1 + 1);
	}
	else
	{
		int r = i + dr[k];
		int c = j + dc[k];
		if (r >= 1 && r <= N && c >= 1 && c <= N && arr[r][c].type == 0)
		{
			visited[r][c] = true;
			DFS(r, c, k, num + 1);
			visited[r][c] = false;
		}
	}
}