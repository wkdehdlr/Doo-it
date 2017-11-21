#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

struct jum {
	int x;
	int y;
	int size;
};

bool operator<(jum t, jum u) {
	if (t.size == u.size)
	{
		return t.x < u.x;
	}
	else
	{
		return t.size > u.size;
	}
}

priority_queue<jum> total_q;
queue<jum> q;
int arr[101][101];
bool visited[101][101];
int T, N;

void BFS(int,int);
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		memset(visited, false, sizeof(visited));
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (arr[i][j] != 0 && visited[i][j] == false)
				{
					q.push({ i,j,i*j });
					visited[i][j] = true;
					BFS(i,j);
				}

			}
		}
		printf("#%d %d", tc + 1, total_q.size());
		while (!total_q.empty())
		{
			int x = total_q.top().x;
			int y = total_q.top().y;
			total_q.pop();
			printf(" %d %d", y, x);
		}
		printf("\n");
	}
}

void BFS(int i, int j)
{
	int x = 0;
	int y = 0;
	while (!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 1 && r <= N && c >= 1 && c <= N && visited[r][c] == false && arr[r][c] != 0)
			{
				visited[r][c] = true;
				q.push({ r,c,r*c });
			}

		}
	}
	total_q.push({ y - j + 1,x - i + 1, (y - j + 1)*(x - i + 1) });
}