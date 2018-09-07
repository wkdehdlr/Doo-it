#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#define MOD 1000000000
int arr[20];
int N;
int dp[1000001][20];
int func(int n, int k)
{
	if (n == 0)return 1;
	int& ret = dp[n][k];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = k; i >= 0; --i) {
		if (n - arr[i] >= 0) {
			ret += (func(n - arr[i], i) % MOD);
			ret %= MOD;
		}
	}
	return ret % MOD;
}
int main()
{
	arr[0] = 1;
	for (int i = 1; i < 20; ++i)arr[i] = 1 << i;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%d\n", func(N, 19) % MOD);
}