#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dr[3] = { 0,1,0 };
int dc[3] = { -1,0,1 };
int N, M;
int arr[1001][1001];
int dp[1001][1001][3];
int func(int x, int y, int k)
{
	if (x == N && y == M)return arr[x][y];
	int& ret = dp[x][y][k];
	if (ret != -1)return ret;
	ret = -987654321;
	int st = 0, en = 3;
	if (k == 0)
		en = 2;
	if (k == 2)
		st = 1;

	for (int i = st; i < en; ++i) {
		int r = x + dr[i];
		int c = y + dc[i];
		if (r >= 1 && r <= N && c >= 1 && c <= M) {
			ret = max(ret, func(r, c, i) + arr[x][y]);
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%d", &arr[i][j]);
	printf("%d\n", func(1, 1, 1));
}