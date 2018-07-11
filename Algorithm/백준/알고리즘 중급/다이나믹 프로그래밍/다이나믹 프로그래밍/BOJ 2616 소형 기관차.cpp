#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, M, tmp;
int arr[50001];
int dp[4][50001];
int func2(int n)
{
	if (n + M - 1 <= N) {
		return arr[n + M - 1] - arr[n - 1];
	}
	return 0;
}
int func(int ktx , int n)
{
	if (n > N + 1)return 0;
	if (ktx > 3)return 0;

	int& ret = dp[ktx][n];
	if (ret != -1)return ret;
	ret = 0;
	return ret = max(func(ktx + 1, n + M) + func2(n), func(ktx, n + 1));
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &tmp);
		arr[i] = arr[i - 1] + tmp;
	}
	scanf("%d", &M);
	printf("%d\n",func(1, 1));
}