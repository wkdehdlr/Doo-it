#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#define MOD 1000000
typedef long long ll;

char str[5005];
ll dp[5005];
int len;
int m_atoi(int i)
{
	int res = str[i - 1] - '0';
	res *= 10;
	res += (str[i] - '0');
	return res;
}
int main()
{
	scanf("%s", str);
	len = strlen(str);
	if (str[0] == '0') {
		printf("0\n");
		return 0;
	}
	for (int i = len - 1; i >= 0; --i) {
		str[i + 1] = str[i];
	}

	dp[1] = 1;
	int res = m_atoi(2);
	if (res <= 26)dp[2] = 2;
	else dp[2] = 1;

	if (str[2] == '0')dp[2] = 1;




	for (int i = 3; i <= len; ++i) {
		if (str[i] == '0') {
			dp[i] += (dp[i - 2] % MOD);
			//dp[i] %= MOD;
			continue;
		}
		
		if (str[i - 1] == '0') {
			dp[i] += (dp[i - 1] % MOD) ;
			//dp[i] %= MOD;
			continue;
		}

		int res = m_atoi(i);

		if (res <= 26) {
			dp[i] = dp[i - 2] % MOD + dp[i - 1] % MOD;
			//dp[i] %= MOD;
		}
		else {
			dp[i] += dp[i - 1] % MOD;
			//dp[i] %= MOD;
		}

	}
	printf("%lld\n", dp[len] % MOD);
}