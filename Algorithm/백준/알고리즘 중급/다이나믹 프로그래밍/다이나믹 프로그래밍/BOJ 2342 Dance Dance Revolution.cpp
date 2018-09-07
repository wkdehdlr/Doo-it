#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int idx = 1;
int N;
int dp[100001][5][5];
int arr[100005];
int func2(int from, int to)
{
	if (!from)return 2;
	if (from == to)return 1;
	int res = abs(from - to);
	if (res == 1 || res == 3)return 3;
	return 4;
}
int func(int n, int left, int right)
{
	if (n == idx)return 0;
	int& ret = dp[n][left][right];
	if (ret != -1)return ret;
	ret = 0;
	return ret = min(func(n + 1, arr[n + 1], right) + func2(left, arr[n + 1]), func(n + 1, left, arr[n + 1]) + func2(right, arr[n + 1]));
}
int main()
{
	memset(dp, -1, sizeof(dp));
	while (1){
		scanf("%d", &N);
		if (!N)break;
		arr[idx++] = N;
	}
	idx--;
	printf("%d\n", func(0, 0, 0));
}