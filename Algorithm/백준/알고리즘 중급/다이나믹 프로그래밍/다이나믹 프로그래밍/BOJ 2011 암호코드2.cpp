#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#define MOD 10000000000
typedef long long ll;

char str[5001];
ll dp[5002];
int N;
int len;
ll func(int n)
{
	if (n == len - 1 || n == len)return 1;

	ll& ret = dp[n];
	if (ret != -1)return ret;
	ret = 0;

	if (n + 1 < len) {
		if (str[n + 1] != '0') {
			ret += (func(n + 1) % MOD);
			ret %= MOD;
		}

		int res = str[n] - '0';
		res *= 10;
		res += str[n + 1] - '0';
		if (res <= 26 && str[n + 2] != '0') {
			ret += (func(n + 2) % MOD);
			ret %= MOD;
		}
	}
	return ret %= MOD;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%s", str);
	len = strlen(str);
	if (str[0] == '0') {
		printf("0\n");
		return 0;
	}
	printf("%lld\n", func(0));
}