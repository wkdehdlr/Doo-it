#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int dp[1001];
int arr[1001];
int func(int n)
{
	if (n == N)return 0;
	int& ret = dp[n];
	if (ret != -1)return ret;
	
	for (int i = 1; i <= N; ++i) {
		if (n + i <= N) {
			ret = max(ret, func(n + i) + arr[i]);
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	printf("%d\n", func(0));
}