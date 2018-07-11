#pragma warning(disable : 4996)
#include<cstdio>

int N, S, M;
int arr[101];
bool dp[101][1001];
int main()
{
	scanf("%d %d %d", &N, &S, &M);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	dp[0][S] = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= M; ++j) {
			if (dp[i][j]) {
				if (j + arr[i + 1] <= M)dp[i + 1][j + arr[i + 1]] = true;
				if (j - arr[i + 1] >= 0 )dp[i + 1][j - arr[i + 1]] = true;
			}
		}
	}
	int ret = -1;
	for (int i = 0; i <= M; ++i)
		if (dp[N][i])ret = i;
	printf("%d\n", ret);
}