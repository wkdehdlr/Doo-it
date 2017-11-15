#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>
using namespace std;

struct core {
	int x;
	int y;
	int dir;
};
core dir_arr[12];


int dr[4] = { 0,1,0,-1};
int dc[4] = { -1,0,1,0 };

int arr[13][13];
bool visited[13][13];
bool visited_temp[13][13];
int T, N, cnt = 0;
int dir_sum = 0;
int core_sum = 0;

int dir_min = 0x7fffffff;
int core_max = 0;

int DFS(int, int, int, int);
void start(int);
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		dir_min = 0x7fffffff;
	    core_max = 0;
		cnt = 0;
		memset(visited, false, sizeof(visited));
		memset(visited_temp, false, sizeof(visited_temp));
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 1)//코어면
				{
					visited[i][j] = true;
					if (!(i == 1 || i == N || j == 1 || j == N))//가장자리에있는 코어가 아니면
					{
						dir_arr[cnt].x = i;
						dir_arr[cnt].y = j;
						cnt++;//가장자리가 아닌 코어가 몇개인지 알수있음
					}
				}
			}
		}
		start(0);
		printf("#%d %d\n", tc + 1, dir_min);
	}
}
void start(int num)
{
	if (num == cnt)
	{
		memcpy(visited_temp, visited, sizeof(visited_temp));
		core_sum = 0;
		dir_sum = 0;
		for (int i = 0; i < cnt; ++i)//정해진 dir로 맵 세팅
		{
			DFS(dir_arr[i].x, dir_arr[i].y, dir_arr[i].dir, 0);
		}

		if (core_max < core_sum)
		{
			core_max = core_sum;
			dir_min = dir_sum;
		}
		else if (core_max == core_sum)
		{
			if (dir_min > dir_sum)
				dir_min = dir_sum;
		}
	}
	else
	{
		for (int i = 0; i < 4; ++i)//코어별 dir을 정하는 단계
		{
			dir_arr[num].dir = i;
			start(num + 1);
		}
	}
}
int DFS(int r, int c, int dir,int num)
{
	if (r == 1 || r == N || c == 1 || c == N)
	{
		dir_sum += num;
		core_sum++;
		return 1;
	}
	else
	{
		int new_r = r + dr[dir];
		int new_c = c + dc[dir];
		int res;

		if (new_r >= 1 && new_r <= N && new_c >= 1 && new_c <= N && visited_temp[new_r][new_c] == false)
		{
			visited_temp[new_r][new_c] = true;
			res =  DFS(new_r, new_c, dir, num + 1);
			if (res == 0)
			{
				visited_temp[new_r][new_c] = false;
				return 0;
			}
			return res;
		}
		else
		{
			return 0;
		}
	}
}