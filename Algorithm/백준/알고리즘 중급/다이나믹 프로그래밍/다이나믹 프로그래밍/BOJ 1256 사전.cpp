#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, M, K;
int idx = 0;
char str[210];
int dp[101][101];
int func(int n, int m)
{
	if (n < 0 || m < 0)return 0;
	int& ret = dp[n][m];
	if (ret != -1)return ret;
	if (n == 1 && m == 0)return ret = 1;
	if (n == 0 && m == 1)return ret = 1;

	return ret = min(func(n - 1, m) + func(n, m - 1), 1000000000);
}
void go(int n, int m, int k)
{
	if (n == 0 && m == 0) {
		str[idx] = '\0';
		return;
	}
	if (n == 0 && m != 0) {
		while (m--)str[idx++] = 'z';
		str[idx] = '\0';
		return;
	}
	if (n != 0 && m == 0) {
		while (n--)str[idx++] = 'a';
		str[idx] = '\0';
		return;
	}
	if (k <= dp[n - 1][m]) {
		str[idx++] = 'a';
		go(n - 1, m, k);
	}
	else {
		str[idx++] = 'z';
		go(n, m - 1, k - dp[n - 1][m]);
	}
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &N, &M, &K);
	if (func(N, M) < K) {
		printf("-1\n");
		return 0;
	}
	go(N, M, K);
	printf("%s\n", str);
	return 0;
}