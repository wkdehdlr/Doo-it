#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int dp[1001][2];
int func(int n, int k)
{
	int& ret = dp[n][k];
	if (ret != -1)return ret;
	ret = 1;
	if (k == 1)
	{
		for (int i = n + 1; i <= N; ++i)
		{
			if (arr[n] < arr[i]) {
				ret = max(ret, func(i, 1) + 1);
			}
			if (arr[n] > arr[i]) {
				ret = max(ret, func(i, 0) + 1);
			}
		}
	}
	else
	{
		for (int i = n + 1; i <= N; ++i)
		{
			if (arr[n] > arr[i]) {
				ret = max(ret, func(i, 0) + 1);
			}
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	int ret = 0;
	for (int i = 1; i <= N; ++i)
		ret = max(max(ret, func(i, 1)), func(i, 0));
	printf("%d\n", ret);
}