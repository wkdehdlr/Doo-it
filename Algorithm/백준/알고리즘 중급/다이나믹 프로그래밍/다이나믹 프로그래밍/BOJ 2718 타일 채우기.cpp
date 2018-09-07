#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int dp[101];
int T;
int N;
int func(int n)
{
	if (n == 0)return 1;
	if (n < 0)return 0;

	int& ret = dp[n];
	if (ret != -1)return ret;
	return ret = func(n - 2) + func(n - 1);
}
int func2(int n)
{

}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int ret = func(N) * func(N);
		
	}
}