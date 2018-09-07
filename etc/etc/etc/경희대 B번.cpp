#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,-1,0,1 };

int N, M, X, Y;
int dp[301][301][4];
int func(int x, int y, int dir)
{
	if (x == X && y == Y)return 0;
	int& ret = dp[x][y][dir];
	if (ret != -1)return ret;
	ret = 987654321;

	//1¹ø
	if (x + dr[dir] >= 0 && x + dr[dir] <= N && y + dc[dir] >= 0 && y + dc[dir] <= M)
		ret = min(ret, func(x + dr[dir], y + dc[dir], (dir + 1) % 4) + 1);
	//2¹ø
	int new_dir = (dir + 1) % 4;
	if (x + dr[new_dir] >= 0 && x + dr[new_dir] <= N && y + dc[new_dir] >= 0 && y + dc[new_dir] <= M)
		ret = min(ret, func(x + dr[new_dir], y + dc[new_dir], new_dir) + 1);
	//3¹ø
	return ret = min(ret, func(x, y, (dir + 1) % 4) + 1);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d %d", &N, &M, &X, &Y);
	printf("%d\n", func(0, 0, 0));
}