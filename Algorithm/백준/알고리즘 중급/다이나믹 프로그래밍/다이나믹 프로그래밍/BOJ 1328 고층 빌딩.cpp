#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#define MOD 1000000007
typedef long long ll;
int N, L, R;

ll dp[101][101][101];
ll func(int n, int l, int r)
{
	if (n <= 0 || l <= 0 || r <= 0)return 0;
	if (n == 1 && l == 1 && r == 1)return 1;
	if (n == 2 && l == 1 && r == 2)return 1;
	if (n == 2 && l == 2 && r == 1)return 1;
	ll& ret = dp[n][l][r];
	if (ret != -1)return ret;
	return ret = func(n - 1, l - 1, r) % MOD + func(n - 1, l, r - 1) % MOD + (func(n - 1, l, r)*(n - 2)) % MOD;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &N, &L, &R);
	printf("%lld\n", func(N, L, R) % MOD);
}