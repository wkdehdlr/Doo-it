#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

long long dp[2501];
int T, L;
void catalan()
{
	for (int i = 2; i <= 2500; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] += dp[j] * dp[i - 1 - j];
			dp[i] %= 1000000007;
		}
	}
}

int main()
{
	scanf("%d", &T);
	dp[0] = 1; dp[1] = 1;
	catalan();
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d", &L);
		if (L % 2 == 1)printf("0\n");
		else {
			printf("%lld\n", dp[L / 2]);
		}
	}
}
