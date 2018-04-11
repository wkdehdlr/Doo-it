#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[13];
int mon[13];
int cost[4];
int T;

int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d %d %d %d", &cost[0], &cost[1], &cost[2], &cost[3]);
		for (int i = 1; i <= 12; ++i)
		{
			scanf("%d", &mon[i]);
		}

		if (mon[1])dp[1] = min(mon[1] * cost[0], cost[1]);
		if (mon[2])dp[2] = dp[1] + min(mon[2] * cost[0], cost[1]);
		else dp[2] = dp[1];			
		if (mon[3])dp[3] = min(dp[2] + min(mon[3] * cost[0], cost[1]), cost[2]);
		else dp[3] = dp[2];

		for (int i = 4; i <= 12; ++i)
		{
			if (mon[i])
				dp[i] = min(dp[i - 1] + min(mon[i] * cost[0], cost[1]), dp[i - 3] + cost[2]);
			else
				dp[i] = dp[i - 1];
		}
		printf("#%d %d\n", tc + 1, min(dp[12], cost[3]));
	}
}
