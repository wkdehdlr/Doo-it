#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
typedef long long ll;
int N;
int arr[101][101];
ll dp[101][101];
ll func(int x, int y)
{
	if (x > N || y > N)return 0;
	if (x == N && y == N)return 1;
	if (!arr[x][y])return 0;
	ll& ret = dp[x][y];
	if (ret != -1)return ret;
	return ret = func(x + arr[x][y], y) + func(x, y + arr[x][y]);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			scanf("%d", &arr[i][j]);
	printf("%lld\n", func(1, 1));
}