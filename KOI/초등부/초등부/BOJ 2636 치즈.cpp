#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
queue<info> q;
bool visited[101][101];
int arr[101][101];
int R, C;
int res = 0;
int res2 = 0;
bool BFS()
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
			if (r >= 1 && r <= R && c >= 1 && c <= C && !visited[r][c])
			{
				if (!arr[r][c]) {
					visited[r][c] = true;
					q.push({ r,c });
				}
				else {
					arr[r][c] = 2;
				}
			}
		}
	}
	res2 = 0;
	int cnt = 0;
	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j) {
			if (arr[i][j] == 2) {
				arr[i][j] = 0; 
				res2++;
			}
			if (!arr[i][j])cnt++;
			visited[i][j] = false;
		}
	res++;
	if (R * C == cnt)
		return true;
	return false;
}

int main()
{
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j)
			scanf("%d", &arr[i][j]);

	while (1)
	{
		q.push({ 1,1 });
		visited[1][1] = true;
		if (BFS())
			break;
	}
	printf("%d\n%d\n", res, res2);
	return 0;
}