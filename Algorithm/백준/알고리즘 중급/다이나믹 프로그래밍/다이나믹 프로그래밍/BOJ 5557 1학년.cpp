#pragma warning(disable : 4996)
#include<cstdio>

int N;
int arr[101];
long long dp[101][21];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	dp[1][arr[1]] = 1;
	for (int i = 1; i < N - 1; ++i) {
		for (int j = 0; j <= 20; ++j) {
			if (dp[i][j]) {
				if (j + arr[i + 1] <= 20)dp[i + 1][j + arr[i + 1]] += dp[i][j];
				if (j - arr[i + 1] >= 0)dp[i + 1][j - arr[i + 1]] += dp[i][j];
			}
		}
	}
	printf("%lld\n", dp[N - 1][arr[N]]);
}