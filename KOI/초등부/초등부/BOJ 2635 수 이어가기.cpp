#pragma warning(disable : 4996)
#include<cstdio>

int dp[100000];
int func(int i, int num, bool flag)
{
	int idx = 3;
	dp[1] = num;
	dp[2] = i;
	if (flag)
	{
		printf("%d %d ", dp[1], dp[2]);
		while (dp[idx - 2] - dp[idx - 1] >= 0)
		{
			dp[idx] = dp[idx - 2] - dp[idx - 1];
			printf("%d ", dp[idx]);
			idx++;
		}
		printf("\n");
		return 0;
	}
	while (dp[idx - 2] - dp[idx - 1] >= 0)
	{
		dp[idx] = dp[idx - 2] - dp[idx - 1];
		idx++;
	}
	return idx;
}
int main()
{
	int idx = 0;
	int mx = 0;
	int num;
	scanf("%d", &num);
	for (int i = num; i > num / 2; --i)
	{
		int res = func(i, num, false);
		if (res > mx) {
			mx = res;
			idx = i;
		}
	}
	printf("%d\n", mx - 1);
	func(idx, num, true);
}