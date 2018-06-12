#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int N;
int dp[100001];
int func(int n)
{
	if (n == 0)return 0;
	int& ret = dp[n];
	if (ret != -1)return ret;

	ret = 987654321;
	int j = (int)sqrt(n);
	for (int i = 1; i <= j; ++i) {
		if (n >= i * i)
			ret = min(ret, func(n - i * i) + 1);
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%d\n", func(N));
}