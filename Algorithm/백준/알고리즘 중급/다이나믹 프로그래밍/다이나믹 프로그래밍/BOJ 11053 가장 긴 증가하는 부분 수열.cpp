#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int dp[1002];
int arr[1001];
int func(int n)
{
	int& ret = dp[n];
	if (ret != -1)return ret;
	ret = 1;
	for (int j = n + 1; j <= N; ++j) {
		if (arr[n] < arr[j]) {
			ret = max(ret, func(j) + 1);
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	printf("%d\n", func(0) - 1);
}