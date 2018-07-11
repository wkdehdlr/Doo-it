#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
typedef long long ll;

ll dp[65][10];
int T, N;
ll func(int n, int num)
{
	if (n == 1)return 1;
	ll& ret = dp[n][num];
	if (ret != -1)return ret;
	ret = 0;
	if (num == 0)
		return ret = func(n - 1, 0);
	for (int i = num; i >= 0; --i)
		ret += func(n - 1, i);
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		ll ret = 0;
		for (int i = 0; i <= 9; ++i)
			ret += func(N, i);
		printf("%lld\n", ret);
	}
}