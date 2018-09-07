#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int N, double M;
int cal[5001];
double price[5001];
double dp[5000];
double func(int n)
{
	double& ret = dp[n];
	if (ret != -1)return ret;
}
int main()
{
	while (1) {
		scanf("%d %lf", &N, &M);
		for (int i = 1; i <= N; ++i)scanf("%d %lf", &cal[i], &price[i]);
		int ret = 0;
		while (func(ret) < M)ret++;
		printf("%d\n", ret);
	}
}