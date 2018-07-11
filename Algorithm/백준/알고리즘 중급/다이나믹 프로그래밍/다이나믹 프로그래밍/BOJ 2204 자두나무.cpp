#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T, W;
int arr[1001];
int dp[1001][3][31];
int func(int t, int loc, int w)
{
	if (t > T)return 0;
	int& ret = dp[t][loc][w];
	if (ret != -1)return ret;

	if (arr[t] == loc) {
		ret = func(t + 1, loc, w) + 1;
		if (w) {
			ret = max(ret, func(t + 1, 3 - loc, w - 1));
		}
	}
	else {
		ret = func(t + 1, loc, w);
		if (w) {
			ret = max(ret, func(t + 1, 3 - loc, w - 1) + 1);
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &T, &W);
	for (int i = 1; i <= T; ++i)scanf("%d", &arr[i]);
	printf("%d\n", max(func(1, 1, W), func(1, 2, W)));
}