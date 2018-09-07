#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[1001][1001];
int arr[1001];
int N;
int func(int team, int idx)
{
	int& ret = dp[team][idx];
	if (ret != -1)return ret;

	return ret = min(func(team, idx + 1), func(team + 1, idx + 1));
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	printf("%d\n", func(1, 1));
}