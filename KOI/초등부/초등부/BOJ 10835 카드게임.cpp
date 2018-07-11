#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int L[2001], R[2001];
int dp[2001][2001];
int func(int l, int r)
{
	if (l > N || r > N)return 0;
	int& ret = dp[l][r];
	if (ret != -1)return ret;
	ret = 0;
	if (L[l] > R[r])
		ret = func(l, r + 1) + R[r];

	return ret = max(ret, max(func(l + 1, r), func(l + 1, r + 1)));	
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &L[i]);
	for (int i = 1; i <= N; ++i)scanf("%d", &R[i]);
	printf("%d\n", func(1, 1));
}