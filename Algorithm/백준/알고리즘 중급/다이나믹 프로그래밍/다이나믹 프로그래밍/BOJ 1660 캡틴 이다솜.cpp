#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[300001];
int arr[201];
int N;
int func(int n)
{
	if (n == 0)return 0;
	int& ret = dp[n];
	if (ret != -1)return ret;
	ret = 987654321;
	for (int i = 1; i <= 200; i++) {
		if (n >= arr[i]) {
			ret = min(ret, func(n - arr[i]) + 1);
		}
		else break;
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	arr[1] = 1;
	for (int i = 2; i <= 200; ++i)arr[i] = arr[i - 1] + i;
	for (int i = 2; i <= 200; ++i)arr[i] = arr[i] + arr[i - 1];
	scanf("%d", &N);
	for (int i = 1; i <= 300000; ++i)func(i);
	printf("%d\n", func(N));
}