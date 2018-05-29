#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int arr[10005];
int dp[10005][3];
int func(int n, int k)
{
	if (n == N) {
		if (k == 2)return 0;
		else return arr[n];
	}
	int& ret = dp[n][k];
	if (ret != -1)return ret;

	if (k == 0 || k == 1)
		return ret = max(func(n + 1, 0), func(n + 1, k + 1) + arr[n]);
	if (k == 2)
		return ret = func(n + 1, 0);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	arr[0] = 0;
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	printf("%d\n", func(1, 0));
	return 0;
}