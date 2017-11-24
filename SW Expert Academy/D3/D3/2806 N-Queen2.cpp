#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int dr[8] = { 0,-1,1,-1,0,1,1,1 };
int dc[8] = { -1,-1,0,1,1,1,0,-1 };
int T, N;
int arr[11][11];
int total_cnt;

struct info {
	int x;
	int y;
	int dir;
};
queue<info> q;
vector<vector<bool> > visited(11, vector<bool>(11));
vector<vector<bool> > visited_temp(11, vector<bool>(11));

void set_arr(int, int, int);
void BFS(int, int,int);
int main()
{
	vector<vector<bool> > temp(11, vector<bool>(11));
	queue<info> q_temp;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		q = q_temp;
		total_cnt = 0;
		scanf("%d", &N);
		visited_temp = visited = temp;
		for (int j = 1; j <= N; ++j)
		{
			visited = visited_temp;
			arr[1][j] = 1;
			BFS(1, j, 8);
			arr[1][j] = 0;
		}
		printf("#%d %d\n", tc + 1, total_cnt);
	}
}
void BFS(int i, int j, int t)
{
	if (i == N)
	{
		int cnt = 0;
		for (int x = 1; x <= N; ++x)
		{
			for (int y = 1; y <= N; ++y)
			{
				if (arr[x][y])
					cnt++;
			}
		}
		if (cnt == N)
			total_cnt++;
	}
	else
	{
		q.push({ i,j,t });
		visited[i][j] = true;
		while (!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			int dir = q.front().dir;
			q.pop();
			if (dir == 8)
			{
				for (int k = 0; k < 8; ++k)
				{
					int r = x + dr[k];
					int c = y + dc[k];
					if (r >= 1 && r <= N && c >= 1 && c <= N)
					{
						visited[r][c] = true;
						q.push({ r,c,k });
					}
				}
			}
			else
			{
				int r = x + dr[dir];
				int c = y + dc[dir];
				if (r >= 1 && r <= N && c >= 1 && c <= N)
				{
					visited[r][c] = true;
					q.push({ r,c,dir });
				}
			}
		}
		vector<vector<bool> > visited_temp2;
		visited_temp2 = visited;
		for (int y = 1; y <= N; ++y)
		{
			if (!visited[i + 1][y])
			{
				arr[i + 1][y] = 1;
				BFS(i + 1, y, 8);
				arr[i + 1][y] = 0;
				visited = visited_temp2;
			}
		}
	}
}
void set_arr(int i, int j, int t)
{
	visited[i][j] = true;
	if (t == 8)
	{
		for (int k = 0; k < 8; ++k)
		{
			int r = i + dr[k];
			int c = j + dc[k];
			if (r >= 1 && r <= N && c >= 1 && c <= N)
			{
				set_arr(r, c, k);
			}
		}
	}
	else
	{
		int r = i + dr[t];
		int c = j + dc[t];
		if (r >= 1 && r <= N && c >= 1 && c <= N)
		{
			set_arr(r, c, t);
		}
	}
}