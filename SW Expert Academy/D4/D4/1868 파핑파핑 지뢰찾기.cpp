#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int dr[8] = { 0,1,1,1,0,-1,-1,-1 };
int dc[8] = { -1,-1,0,1,1,1,0,-1 };
struct info {
	int x;
	int y;
};
queue<info> q;

int cnt[301][301];
char arr[301][301];
char temp;
int N, T;

int set();
void BFS();
int main()
{
	scanf("%d", &T);
	scanf("%c", &temp);//	scanf("%c", &temp);
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d", &N);
		scanf("%c", &temp);//scanf("%c", &temp);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%c", &arr[i][j]);
				if (arr[i][j] == '*')
				{
					for (int k = 0; k < 8; ++k)
					{
						int x = i + dr[k];
						int y = j + dc[k];
						if (x >= 1 && x <= N && y >= 1 && y <= N)
							cnt[x][y]++;
					}
				}
			}
			scanf("%c", &temp);	//scanf("%c", &temp);
		}
		printf("#%d %d\n", tc + 1, set());
		memset(cnt, 0, sizeof(cnt));
		memset(arr, 0, sizeof(arr));
	}
}
int set()
{
	int total_cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (arr[i][j] == '.' && !cnt[i][j])
			{
				total_cnt++;
				arr[i][j] = '0';
				q.push({ i,j });
				BFS();
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (arr[i][j] == '.')
				total_cnt++;
		}
	}
	return total_cnt;
}
void BFS()
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int k = 0; k < 8; ++k)
		{
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 1 && r <= N && c >= 1 && c <= N && arr[r][c] == '.')
			{
				if (!cnt[r][c])
				{
					arr[r][c] = '0';
					q.push({ r,c });
				}
				else
				{
					arr[r][c] = cnt[r][c] + '0';
				}
			}
		}
	}
}