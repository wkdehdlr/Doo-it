#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int func(int n)
{
	if (n == N)return 0;
	if (n>N)return 987654321;

	int& ret = dp[n];
	if (ret != -1)return ret;

	ret = 987654321;
	for (int i = 1; i <= arr[n]; ++i)
	{
		ret = min(ret, func(n + i) + 1);
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	if (func(1) == 987654321)
		printf("-1\n");
	else
		printf("%d\n", func(1));
}