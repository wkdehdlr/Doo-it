#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
ll dp[1001][1001][2];
int N, K, ok;
ll func(int n, int k, int t)
{
	//±âÀú»ç·Ê
	if (ok == 1) {
		if (n == N) {
			if (t == 1)return 0;
			else {
				if (k == K)return 1;
				else return 0;
			}
		}
		if (n == N - 1) {
			if (k == K)return 1;
			else return 0;
		}
	}
	else {//ok == 2
		if (n == N - 1) {
			if (t == 1) {
				if (k == K)return 1;
				else return 0;
			}
		}
		if (n == N) {
			if (k == K)return 1;
			else return 0;
		}
	}

	ll& ret = dp[n][k][t];
	if (ret != -1)return ret;

	if (t == 1)
		return ret = func(n + 2, k + 1, 1) % 1000000003 + func(n + 2, k, 0) % 1000000003;
	else
		return ret = func(n + 1, k + 1, 1) % 1000000003 + func(n + 1, k, 0) % 1000000003;
}

int main()
{
	scanf("%d %d", &N, &K);
	ok = 1;	memset(dp, -1, sizeof(dp));
	ll res1 = func(1, 1, 1) % 1000000003;
	ok = 2;	memset(dp, -1, sizeof(dp));
	ll res2 = func(1, 0, 0) % 1000000003;
	printf("%lld\n", (res1 + res2) % 1000000003);
}