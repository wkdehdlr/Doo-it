#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char str[2510];
int dp[2510][2510];
int dp2[2510];
int len;
int func(int f, int e)
{
	int& ret = dp[f][e];
	if (ret != -1)return ret;
	if (f > e)return ret = 0;
	if (f == e)return ret = 1;
	if (f + 1 == e) {
		if (str[f] == str[e])return ret = 1;
		else return ret = 0;
	}

	if (str[f] == str[e] && func(f + 1, e - 1))
		return ret = 1;
	else return ret = 0;
}
int func2(int n)
{
	int& ret = dp2[n];
	if (ret != -1)return ret;
	if (dp[0][n] == 1)return ret = 1;
	ret = 987654321;
	for (int i = 1; i <= n; ++i) {
		if (dp[i][n] == 1) {
			ret = min(ret, func2(i - 1) + 1);
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));
	scanf("%s", str);
	len = strlen(str);
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
			func(i, j);
	printf("%d\n", func2(len - 1));
}