#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1 << 21][51];
int n, m;
pair<int, int> a[51];
int func(int state, int pos) {
	if (pos == m)return 0;
	//int &ret = dp[state][pos];
	if (dp[state][pos] != -1)return dp[state][pos];
	int x = a[pos].first;
	int y = a[pos].second;
	int temp = state;
	if (!((1 << x)&state) && !((1 << y)&state)) 
	{
		temp |= (1 << x);
		temp |= (1 << y);
		dp[state][pos] = max(dp[state][pos], func(temp, pos + 1) + 2);
	}
	return dp[state][pos] = max(dp[state][pos], func(state, pos + 1));
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &a[i].first, &a[i].second);
	memset(dp, -1, sizeof(dp));
	int res = func(0, 0);
	if (res != n)res++;
	printf("%d\n", res);
	return 0;
}