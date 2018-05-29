#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
int dp[50][2];
int N, T;
int func(int n, int num)
{
	if (n == 1) {
		if (n == num)return 1;
		else return 0;
	}
	if (n == 0) {
		if (n == num)return 1;
		else return 0;
	}

	int& ret = dp[n][num];
	if (ret != -1)return ret;
	return ret = func(n - 2, num) + func(n - 1, num);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	func(40, 0);
	func(40, 1);
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		printf("%d %d\n", func(N, 0), func(N, 1));
	}
}