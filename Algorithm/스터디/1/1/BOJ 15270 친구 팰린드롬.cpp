#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#define MAX(a,b) a>b?a:b;
struct info {
	int x1, x2;
};

int dp[50][2097152];//2^21
info inf[50];
int N, M;

int func(int degree, int status)
{
	if (degree == M)
		return 0;
	if (dp[degree][status] != -1)return dp[degree][status];

	int x1 = inf[degree].x1;
	int x2 = inf[degree].x2;
	int temp = status;

	if (!(status & (1 << x1)) && !(status &(1 << x2)))
	{
		temp |= (1 << x1);
		temp |= (1 << x2);
		dp[degree][status] = MAX(dp[degree][status], func(degree + 1, temp) + 2);
	}
	return dp[degree][status] = MAX(dp[degree][status], func(degree + 1, status));
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &inf[i].x1, &inf[i].x2);
	}
	memset(dp, -1, sizeof(dp));
	int res = func(0, 0);
	if (N - res)res++;
	printf("%d\n", res);
}