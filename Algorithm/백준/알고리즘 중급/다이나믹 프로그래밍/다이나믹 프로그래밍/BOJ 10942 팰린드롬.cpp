#include<cstdio>
#include<cstring>
int N, M, S, E;
int dp[2001][2001];
int arr[2001];
int func(int s, int e)
{
	if (s + 1 == e) {
		if (arr[s] == arr[e])return 1;
		else return 0;
	}
	if (s == e)return 1;

	int& ret = dp[s][e];
	if (ret != -1)return ret;
	if (func(s + 1, e - 1) && arr[s] == arr[e])
		return ret = 1;
	else
		return ret = 0;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	scanf("%d", &M);
	for (int i = 1; i <= M; ++i)
	{
		scanf("%d %d", &S, &E);
		printf("%d\n", func(S, E));
	}
}