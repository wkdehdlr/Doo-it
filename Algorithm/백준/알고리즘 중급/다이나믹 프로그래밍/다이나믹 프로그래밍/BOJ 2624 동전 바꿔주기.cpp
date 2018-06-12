#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int T, K;
int arr[101][2];
int dp[102][10001];
int func(int n, int sum)
{
	if (n == 0) {
		if (sum == 0)return 1;
		else return 0;
	}
	int& ret = dp[n][sum];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i <= arr[n][1]; ++i) {
		if (sum >= i * arr[n][0])
			ret += func(n - 1, sum - i * arr[n][0]);
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &T, &K);
	for (int i = 1; i <= K; ++i)
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	printf("%d\n", func(K, T));
}