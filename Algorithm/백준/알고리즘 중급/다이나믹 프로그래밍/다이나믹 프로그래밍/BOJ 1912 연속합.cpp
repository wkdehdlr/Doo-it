#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int dp[100001];
int arr[100001];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);

	dp[N] = arr[N];
	int ret = dp[N];
	for (int i = N - 1; i >= 1; --i) {
		if (dp[i + 1] < 0) {
			dp[i] = arr[i];
		}
		else {
			dp[i] = dp[i + 1] + arr[i];
		}
		ret = max(ret, dp[i]);
	}
	printf("%d\n", ret);
}
/*
3

5 - 100000 1000001
*/