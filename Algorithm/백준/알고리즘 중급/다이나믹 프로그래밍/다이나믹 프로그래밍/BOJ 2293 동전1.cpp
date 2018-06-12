#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int dp[10001];
int arr[101];
int N, K;
/*
int func(int k)
{
	if (k == 0)return 1;
	int& ret = dp[k];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 1; i <= N; ++i) {
		if (k >= arr[i])
			ret += func(k - arr[i]);
	}
	return ret;
}
*/
int main()
{
	//memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	dp[0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			if (j >= arr[i]) {
				dp[j] += dp[j - arr[i]];
			}
		}
	}
	printf("%d\n", dp[K]);
}