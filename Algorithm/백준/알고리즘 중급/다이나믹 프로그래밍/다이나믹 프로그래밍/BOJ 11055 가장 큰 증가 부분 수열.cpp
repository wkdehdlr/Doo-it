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
	//if (n == N)return arr[n];
	int& ret = dp[n];
	if (ret != -1)return ret;
	ret = arr[n];
	for (int i = n; i <= N; ++i) {
		if (arr[n] < arr[i]) {
			ret = max(ret, func(i) + arr[n]);
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