#pragma warning(disable : 4996)
#include<cstdio>
int arr[7][101], M, cnt = 0;
int dp[7][6000001];
int main()
{
	for (int i = 1; i <= 6; ++i) {
		scanf("%d", &arr[i][0]);
		for (int k = 1; k <= arr[i][0]; ++k) {
			scanf("%d", &arr[i][k]);
		}
	}
	scanf("%d", &M);
	for (int i = 1; i <= arr[1][0]; ++i)
		dp[1][arr[1][i]]++;

	for (int i = 1; i < 6; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (dp[i][j]) {
				for (int k = 1; k <= arr[i + 1][0]; ++k) {
					if (j + arr[i + 1][k] <= M)
						dp[i + 1][j + arr[i + 1][k]] += dp[i][j];
				}
			}
		}
	}
	for (int j = 1; j <= M; ++j)
		cnt += dp[6][j];
	printf("%d\n", cnt);
}