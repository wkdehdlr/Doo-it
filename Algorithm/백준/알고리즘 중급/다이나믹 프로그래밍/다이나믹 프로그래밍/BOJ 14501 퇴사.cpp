#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int arr[16][2];
int dp[16];
int func(int n)
{
	if (n == N + 1)return 0;
	int& ret = dp[n];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = n; i <= N; ++i) {
		if (i + arr[i][0] <= N + 1)
			ret = max(ret, func(i + arr[i][0]) + arr[i][1]);
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d %d", &arr[i][0], &arr[i][1]);
	printf("%d\n", func(1));
}