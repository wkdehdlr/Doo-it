#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
typedef long long ll;
int N, K;
ll dp[201][201];
ll func(int n, int k)
{
	if (k == 0) {
		if (n == 0)return 1;
		else return 0;
	}
	ll& ret = dp[n][k];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i <= n; ++i)
	{
		ret += func(n - i, k - 1) % 1000000000;
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &K);
	printf("%lld\n", func(N,K) % 1000000000);
}