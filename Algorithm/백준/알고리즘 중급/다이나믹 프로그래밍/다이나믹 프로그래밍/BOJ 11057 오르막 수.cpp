#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
typedef long long ll;

ll dp[1001][10];
int N;
int func(int n, int k)
{
	if (n == 1)return 1;
	ll& ret = dp[n][k];
	if (ret != -1)return ret;
	ret = 0;
	if (k == 0)
		return ret = func(n - 1, 0) % 10007;
	for (int i = 0; i < 10; ++i) {
		if (k >= i) {
			ret += func(n - 1, k - i) % 10007;
		}
	}
	return ret;
}
int main()
{
	ll ret = 0;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 0; i < 10; ++i)ret += (func(N, i) % 10007);
	printf("%lld\n", ret % 10007);
}