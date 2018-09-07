#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int dp[31];
int N;
int func(int n)
{
	if (n == 0)return 1;
	if (n < 0)return 0;
	int& ret = dp[n];
	if (ret != -1)return ret;

	return ret = func(n - 1) + 2 * func(n - 2);
}
int main()
{	
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	func(N);
	if (N % 2 == 0)
		printf("%d\n", (func(N) + func(N / 2) + 2 * func(N / 2 - 1)) / 2);
	else
		printf("%d\n", (func(N) + func(N / 2)) / 2);
}