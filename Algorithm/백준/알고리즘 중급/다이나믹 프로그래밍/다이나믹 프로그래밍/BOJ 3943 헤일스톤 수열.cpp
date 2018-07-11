#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T, N;
//int dp[1000001];
int func(int n, int mx)
{
	if (n == 1)return mx;
//	int& ret = dp[n];
	//if (ret != -1)return ret;

	if (n % 2) {//È¦¼ö
		mx = max(n * 3 + 1, mx);
		return func(n * 3 + 1, mx);
	}
	else {//Â¦¼ö
		mx = max(n / 2, mx);
		return func(n / 2, mx);
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
//		memset(dp, -1, sizeof(dp));
		scanf("%d", &N);
		printf("%d\n", func(N, N));
	}
}