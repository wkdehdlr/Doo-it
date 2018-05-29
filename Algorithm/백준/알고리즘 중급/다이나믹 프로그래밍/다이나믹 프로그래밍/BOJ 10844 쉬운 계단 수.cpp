#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
int N;
ll dp[101][10];
ll func(int n,int k)
{
	if (n == 1) {
		if (k == 0)return 0;
		else return 1;
	}
	ll& ret = dp[n][k];
	if (ret != -1)return ret;

	if (k == 0)
		return ret = func(n - 1, 1) % 1000000000;
	if (k == 9)
		return ret = func(n - 1, 8) % 1000000000;
	return ret = func(n - 1, k - 1) % 1000000000 + func(n - 1, k + 1) % 1000000000;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	ll ret = 0;
	for (int k = 0; k <= 9; ++k)ret += (func(N, k) % 1000000000);
	printf("%lld\n", ret % 1000000000);
}