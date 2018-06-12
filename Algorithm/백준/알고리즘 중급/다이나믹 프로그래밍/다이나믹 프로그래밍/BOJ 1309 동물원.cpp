#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int N;
ll dp[100001][3];
ll func(int x, int y)
{
	if (x == N)return 1;
	if (x > N)return 0;
	ll& ret = dp[x][y];
	if (ret != -1)return ret;

	if (y == 0)
		return ret = func(x + 1, 1) % 9901 + func(x + 1, 2) % 9901 + func(x + 1, 0) % 9901;
	if (y == 1)
		return ret = func(x + 1, 2) % 9901 + func(x + 1, 0) % 9901;
	if (y == 2)
		return ret = func(x + 1, 1) % 9901 + func(x + 1, 0) % 9901;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%lld\n", func(0, 0) % 9901);
}