#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int N, M;
int arr[501][501];
int dp[501][501];
int func(int x, int y)
{
	if (x == N && y == M)return 1;
	int& ret = dp[x][y];
	if (ret != -1)return ret;
	ret = 0;
	for (int k = 0; k < 4; ++k) {
		int r = x + dr[k];
		int c = y + dc[k];
		if (r >= 1 && r <= N && c >= 1 && c <= M && arr[x][y] > arr[r][c]) {
			ret += func(r, c);
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
	printf("%d\n", func(1, 1));
}