#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, M;
int arr[101][2];
int dp[101][10001];
int func(int n, int c)
{
	if (n > N)return 0;
	int& ret = dp[n][c];
	if (ret != -1)return ret;
	ret = func(n + 1, c);
	if (c >= arr[n][1])
		ret = max(ret, func(n + 1, c - arr[n][1]) + arr[n][0]);
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i][0]);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i][1]);
	int ret = 0;
	while (func(1, ret) < M)ret++;
	printf("%d\n", ret);
}