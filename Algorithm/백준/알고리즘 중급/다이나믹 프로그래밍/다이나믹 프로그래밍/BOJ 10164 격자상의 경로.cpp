#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int N, M, K, N2, M2;
int dp[16][16];
int func(int x, int y)
{
	if (x > N || y > M)return 0;
	if (x == N && y == M)return 1;
	int& ret = dp[x][y];
	if (ret != -1)return ret;
	return ret = func(x + 1, y) + func(x, y + 1);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &N, &M, &K);
	N2 = N, M2 = M;
	if (K) {
		K % M == 0 ? N = K / M : N = (K / M) + 1;
		K % M == 0 ? M = M : M = K % M;
		int ret = func(1, 1);
		memset(dp, -1, sizeof(dp));
		int n = N, m = M;
		N = N2, M = M2;
		ret *= (func(n, m));
		printf("%d\n", ret);
	}
	else {
		printf("%d\n", func(1, 1));
	}
}