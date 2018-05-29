#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
int N;
long long dp[91][3];
long long func(int n,int num)
{
	//±âÀú»ç·Ê
	if (n == 1) {
		if (num)return 1;
		else return 0;
	}
	long long& ret = dp[n][num];
	if (ret != -1)return ret;

	if (num) {
		ret = func(n - 1, 0);
	}
	else {
		ret = func(n - 1, 1) + func(n - 1, 0);
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%lld\n", func(N, 1) + func(N, 0));
}