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
		check_core2();
		//check_core();
		//link_start();
	}
}
void check_core2()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (arr[i][j].type == 1)//코어면
			{
				visited[i][j] = true;
				if (!(i == 1 || i == N || j == 1 || j == N))//가장자리에있는 코어가 아니면
				{
					for (int k = 0; k < 4; ++k)
					{
						DFS2(i, j, k, 0);
					}
				}
			}
		}
	}
}
void DFS2(int i, int j, int k, int num)
{
	if (i == 1 || i == N || j == 1 || j == N)
	{
		cnt++;0
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
void check_core()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (arr[i][j].type == 1)//코어면
			{
				if (!(i == 1 || i == N || j == 1 || j == N))//가장자리코어가 아니면
				{
					cnt = 0;
					for (int k = 0; k < 4; ++k)
					{
						DFS(i, j, k, 0);
					}
					arr[i][j].sum = cnt;

					if (cnt == 1)
					{
						de.push_front(arr[i][j]);
					}
					else if (cnt == 2)
					{
						de_temp.clear();
						while (!de.empty())
						{
							if (de.front().sum == 1)
							{
								de_temp.push_back(de.front());
								de.pop_front();
							}
						}
						de.push_front(arr[i][j]);
						while (!de_temp.empty())
						{
							de.push_front(de_temp.back());
							de_temp.pop_back();
						}
					}
					else if (cnt == 3)
					{
						de.push_back(arr[i][j]);
					}
				}
			}
		}
	}
}
void DFS(int i, int j,int k,int num)
{
	if (i == 1 || i == N || j == 1 || j == N)
	{
		cnt++;
		arr[i][j].dir[k] = num;
	}
	else
	{
		int r = i + dr[k];
		int c = j + dc[k];
		if (r >= 1 && r <= N && c >= 1 && c <= N && arr[r][c].type == 0)
		{
			DFS(r, c, k, num + 1);
		}
	}
}
void link_start()
{
	while (!de.empty())
	{
		de.front().sum
	}
}