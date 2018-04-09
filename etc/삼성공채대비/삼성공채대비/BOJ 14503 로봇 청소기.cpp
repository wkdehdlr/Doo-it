#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;
struct info {
	int x, y, dir;
};
queue<info> q;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int N, M, dir, x, y, cnt = 0;
int arr[51][51];
bool visited[51][51];
int func_dir(int dir)
{
	int res = 0;
	switch (dir)
	{
	case 0:res = 0; break;
	case 1:res = 3; break;
	case 2:res = 2; break;
	case 3:res = 1; break;
	}
	return res;
}
int func_dir2(int dir)
{
	int res = 0;
	switch (dir)
	{
	case 0:res = 3; break;
	case 1:res = 2; break;
	case 2:res = 1; break;
	case 3:res = 0; break;
	}
	return res;
}
int func_dir3(int dir)
{
	int res = 0;
	switch (dir)
	{
	case 0:res = 1; break;
	case 1:res = 0; break;
	case 2:res = 3; break;
	case 3:res = 2; break;
	}
	return res;
}
void BFS()
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;// 0ºÏ, 1µ¿, 2³², 3¼­
		q.pop();				// 0  , 3  , 2  , 1
		if (!visited[x][y]) {
			visited[x][y] = true;
			cnt++;
		}
		bool done = true;
		int di = func_dir(dir);
		for (int k = 0; k < 4; ++k)
		{
			//di = (di + k) % 4;
			int r = x + dr[(di + k) % 4];
			int c = y + dc[(di + k) % 4];
			if (r >= 1 && r <= 50 && c >= 1 && c <= 50 && !visited[r][c] && !arr[r][c])
			{
				done = false;
				q.push({ r,c, func_dir2((di + k) % 4) });
				break;
			}
		}
		if (done) {
			int tmp = func_dir3(dir);
			if (arr[x + dr[tmp]][y + dc[tmp]])break;
			else {
				q.push({ x + dr[tmp] ,y + dc[tmp] ,dir });
			}
		}
	}
}
int main()
{
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &dir);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	q.push({ x + 1,y + 1,dir });
	BFS();
	printf("%d\n", cnt);
}