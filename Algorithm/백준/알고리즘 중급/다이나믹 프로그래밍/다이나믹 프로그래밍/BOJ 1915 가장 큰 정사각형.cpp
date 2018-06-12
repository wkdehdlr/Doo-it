#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, M;
int arr[1001][1001];
int dp[1001][1001];
int func(int n, int m)
{
	if (n == 1 || m == 1)return arr[n][m];
	int& ret = dp[n][m];
	if (ret != -1)return ret;

	if (arr[n][m] == 1)
		return ret = min(min(func(n - 1, m), func(n, m - 1)), func(n - 1, m - 1)) + 1;
	if (arr[n][m] == 0)
		return ret = 0;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%1d", &arr[i][j]);

	int ret = 0;
	for (int i = N; i >= 1; --i) {
		for (int j = M; j >= 1; --j) {
			ret = max(ret, func(i, j));
		}
	}
	printf("%d\n", ret*ret);
}