#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[21][21];
int dp[21][301];
int N, M;
int func(int idx, int money)
{
	int& ret = dp[idx][money];
	if (ret != -1)return ret;

	for (int i = 1; i <= M; ++i) {
		if (N >= money) {
			ret = max(ret, func(idx + 1, N - money) + arr[2][2]);
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
}