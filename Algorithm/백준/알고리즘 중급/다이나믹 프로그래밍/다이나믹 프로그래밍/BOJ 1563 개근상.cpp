#include<cstdio>
#include<cstring>
using namespace std;
#define MOD 1000000
int N;
long long dp[1001][3][4];
int func(int n, int late, int fail)
{
	if (late == 2 || fail == 3)return 0;
	if (n == 1)return 1;
	long long& ret = dp[n][late][fail];
	if (ret != -1)return ret;
	return ret = func(n - 1, late, 0) % MOD + func(n - 1, late + 1, 0) % MOD + func(n - 1, late, fail + 1) % MOD;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%lld\n", (func(N, 0, 0) % MOD + func(N, 1, 0) % MOD + func(N, 0, 1) % MOD) % MOD);
	return 0;
}