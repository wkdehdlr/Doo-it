#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#define MOD 15746
typedef long long ll;

ll dp[1000001][2];
int N;
ll func(int n, int k)
{
	if (n <= 0)return 0;
	if (n == 1) {
		if (k == 1)return 1;
		if (k == 0)return 0;
	}
	if (n == 2) {
		if (k == 1)return 1;
		if (k == 0)return 1;
	}
	ll& ret = dp[n][k];
	if (ret != -1)return ret;
	if (k == 1)
		return ret = func(n - 1, 1) % MOD + func(n - 1, 0) % MOD;
	if (k == 0)
		return ret = func(n - 2, 0) % MOD + func(n - 2, 1) % MOD;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%lld\n", (func(N, 1) % MOD + func(N, 0) % MOD) % MOD);
}