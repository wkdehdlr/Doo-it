#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int T, N, K;
int dp[101][101][2];
int func(int n, int k, int last)
{
	if (n <= 0 || k < 0)return 0;
	if (n <= k)return 0;
	if (n == 2 && k == 0 && last == 0)return 2;
	if (n == 2 && k == 0 && last == 1)return 1;
	if (n == 2 && k == 1 && last == 0)return 0;
	if (n == 2 && k == 1 && last == 1)return 1;

	int&ret = dp[n][k][last];
	if (ret != -1)return ret;

	if (last)//맨마지막이 1일때
		return ret = func(n - 1, k, 0) + func(n - 1, k - 1, 1);
	else//맨마지막이 0일때
		return ret = func(n - 1, k, 0) + func(n - 1, k, 1);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d %d", &N, &K);
		printf("%d\n", func(N, K, 1) + func(N, K, 0));
	}
}