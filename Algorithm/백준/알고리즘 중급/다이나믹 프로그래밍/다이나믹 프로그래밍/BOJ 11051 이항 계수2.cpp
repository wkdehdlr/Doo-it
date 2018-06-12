#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
typedef long long ll;
int N, K;
ll dp[1001][1001];
ll func(int n, int k)
{
	if (k == 0)return 1;
	if (n == k)return 1;
	if (n < k)return 0;
	ll& ret = dp[n][k];
	if (ret != -1)return ret;
	return ret = func(n - 1, k) % 10007 + func(n - 1, k - 1) % 10007;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &K);
	printf("%lld\n", func(N, K) % 10007);
}