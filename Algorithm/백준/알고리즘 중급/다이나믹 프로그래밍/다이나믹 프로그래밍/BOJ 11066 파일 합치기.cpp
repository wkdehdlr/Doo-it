#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, T;
int arr[501];
int dp[501][501];
int sum[501];
int func(int i, int j)
{
	if (i == j)return arr[i];
	int& ret = dp[i][j];
	if (ret != -1)return ret;
	ret = 987654321;
	for (int k = i; k < j; ++k)
	{
		ret = min(ret, func(i, k) + func(k + 1, j) + sum[j] - sum[i - 1]);
	}
	return ret;
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &arr[i]);
			sum[i] = sum[i - 1] + arr[i];
		}
		printf("%d\n", func(1, N) - sum[N]);
	}
}