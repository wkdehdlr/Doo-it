#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

char str[1010];
int len;
int dp[1010][1010];
int func(int f, int e)
{
	int&ret = dp[f][e];
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
int func2(int f, int e)
{
	if (f == e)return len - 1;
	if (dp[f][e] == 1)return f;
	return func2(f + 1, e);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%s", str);
	len = strlen(str);
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
			func(i, j);
	printf("%d\n", len + func2(0, len - 1));
}