#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[21][21];
int dp[301];
int N, M;
int func(int n, int bit)
{
	if (!n)return 0;
	int& ret = dp[n];
	if (ret != -1)return ret;

	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= M; ++j) {
			if (!(bit & (1 << j))) {
				ret = max(ret, func(n - i, bit | 1 << j) + arr[i][j]);
			}
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &arr[i][0]);
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("%d\n", func(N, 0));
}