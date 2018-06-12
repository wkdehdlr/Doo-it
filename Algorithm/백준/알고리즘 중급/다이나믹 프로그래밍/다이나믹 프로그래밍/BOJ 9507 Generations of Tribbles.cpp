#pragma warning(disable : 4996)
#include<cstdio>
typedef long long ll;

ll dp[70];
int T;
int main()
{
	dp[0] = 1; dp[1] = 1;
	dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 67; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
}