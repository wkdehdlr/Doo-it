#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int N;
int arr[501][501];
int dp[501][501];
int func(int x, int y)
{
	//if (x == 0 || x == N + 1 || y == 0 || y == N + 1)return 0;
	int& ret = dp[x][y];
	if (ret != -1)return ret;
	ret = 1;
	for (int i = 0; i < 4; ++i) {
		int r = x + dr[i];
		int c = y + dc[i];
		if (r >= 1 && r <= N && c >= 1 && c <= N && arr[x][y] > arr[r][c]) {
			ret = max(ret, func(r, c) + 1);
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			scanf("%d", &arr[i][j]);

	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			ret = max(ret, func(i, j));
		}
	}
	printf("%d\n", ret);
}