#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[301][301];
int arr[301][301];
int N, M, K;

int func(int n, int m)
{
	if (m == 0 && n != N)return -987654321;
	if (n == N)return 0;
	int& ret = dp[n][m];
	if (ret != -1)return ret;

	for (int i = n + 1; i <= N; ++i) {
		if (arr[n][i]) {
			ret = max(ret, func(i, m - 1) + arr[n][i]);
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= K; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a < b && arr[a][b] < c)arr[a][b] = c;
	}
	printf("%d\n", func(1, M - 1));
}