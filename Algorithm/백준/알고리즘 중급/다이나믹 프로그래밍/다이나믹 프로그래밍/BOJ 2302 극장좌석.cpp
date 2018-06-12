#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

int N,K;
int dp[41][41];
bool on[41];
int func(int n, int k)
{
	if (on[n]) {//vipÁÂ¼®ÀÏ¶§
		if (n != k)return 0;
	}
	if (n == N)return 1;
	int& ret = dp[n][k];
	if (ret != -1)return ret;

	if (n < k) {
		return ret = func(n + 1, n);
	}
	else {
		ret = func(n + 1, n + 1);
		if (n + 2 <= N) {
			ret += func(n + 1, n + 2);
		}
		return ret;
	}
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &K);
	int num;
	for (int i = 1; i <= K; ++i) {
		scanf("%d", &num);
		on[num] = true;
	}
	printf("%d\n", func(0, 0));
}