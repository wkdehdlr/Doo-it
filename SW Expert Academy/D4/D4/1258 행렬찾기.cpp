#pragma warning(disable : 4966)
#include<cstdio>
#include<queue>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

struct jum {
	int x;
	int y;
};

queue<jum> q;

int arr[101][101];
bool visited[101][101];
int T, N;

void BFS();
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
				scanf("%d", &arr[i][j]);
			}
		}
		q.push({ 1.1 });
		visited[1][1] = true;
		BFS();
	}
}

void BFS()
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 1 && r <= N && c >= 1 && c <= N && visited[r][c] == false && arr[r][c] != 0)
			{

			}
		}
	}
}