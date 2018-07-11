#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int T, K;
int arr[101][2];
int dp[10001][101];
int func(int t, int k)
{
	if (k == 0) {
		if (t == 0)return 1;
		else return 0;
	}
	int& ret = dp[t][k];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i <= arr[k][1]; ++i) {
		if (t >= i * arr[k][0])
			ret += func(t - i * arr[k][0], k - 1);
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &T, &K);
	for (int i = 1; i <= K; ++i)scanf("%d %d", &arr[i][0], &arr[i][1]);
	printf("%d\n", func(T, K));
}