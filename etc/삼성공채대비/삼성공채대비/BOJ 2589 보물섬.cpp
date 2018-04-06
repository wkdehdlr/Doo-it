#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct info {
	int x, y;
};
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int visited[51][51];
char arr[51][51];
int L, W;
int mx = 0;
queue<info> q;
void BFS()
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = visited[x][y];
		if (cnt > mx)
			mx = cnt;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 1 && r <= L && c >= 0 && c < W && arr[r][c] == 'L' && !visited[r][c])
			{
				visited[r][c] = visited[x][y] + 1;
				q.push({ r,c });
			}
		}
	}
}
int main()
{
	mx = 0;
	scanf("%d %d", &L, &W);
	for (int i = 1; i <= L; ++i)
	{
		scanf("%s", arr[i]);
	}

	for (int i = 1; i <= L; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (arr[i][j] == 'L' && !visited[i][j])
			{
				visited[i][j] = 1;
				q.push({ i,j });
				BFS();
				memset(visited, 0, sizeof(visited));
			}
		}
	}
	printf("%d\n", mx - 1);
}