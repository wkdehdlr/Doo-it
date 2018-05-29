#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[1000001], N;
int func(int n)
{
	//기저사례
	if (n == 1)return 0;
	//메모이제이션
	int& ret = dp[n];
	if (ret != -1)return ret;
	ret = 0x7fffffff;
	
	if (!(n % 3))
		ret = min(ret, func(n / 3) + 1);
	if (!(n % 2))
		ret = min(ret, func(n / 2) + 1);
	ret = min(ret, func(n - 1) + 1);
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%d\n", func(N));
}