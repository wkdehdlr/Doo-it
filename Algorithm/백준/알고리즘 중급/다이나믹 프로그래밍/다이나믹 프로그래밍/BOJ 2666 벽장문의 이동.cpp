#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
int n1, n2;
int K;
int arr2[25];
int dp[25][25][25][25];
int func(int n, int l, int r, int k)
{
	if (k == K + 1)return 0;
	int& ret = dp[n][l][r][k];
	if (ret != -1)return ret;
	if (n == l || n == r) {
		return ret = func(arr2[k + 1], l, r, k + 1);
	}

	if (n < l) {
		return ret = func(arr2[k + 1], n, r, k + 1) +abs(n - l);
	}
	if (r < n) {
		return ret = func(arr2[k + 1], l, n, k + 1) +abs(n - r);
	}
	return ret = min(func(arr2[k + 1], n, r, k + 1) + abs(n - l), func(arr2[k + 1], l, n, k + 1) + abs(n - r));
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d %d", &N, &n1, &n2, &K);
	for (int i = 1; i <= K; ++i)scanf("%d", &arr2[i]);
	printf("%d\n", func(arr2[1], n1, n2, 1));
}