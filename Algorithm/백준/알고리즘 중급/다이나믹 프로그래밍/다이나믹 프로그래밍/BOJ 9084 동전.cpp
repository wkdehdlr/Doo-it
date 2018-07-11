#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int T, N, M;
int arr[21];
int dp[21][10001];
int func(int n, int m)
{
	if (n <= 0 || m < 0)return 0;
	if (m == 0)return 1;

	int& ret = dp[n][m];
	if (ret != -1)return ret;

	return ret = func(n, m - arr[n]) + func(n - 1, m);
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
		scanf("%d", &M);
		printf("%d\n", func(N, M));
	}
}