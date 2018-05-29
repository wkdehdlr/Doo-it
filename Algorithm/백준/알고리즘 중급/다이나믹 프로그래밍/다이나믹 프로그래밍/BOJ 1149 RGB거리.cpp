#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int dp[1000][3];
int arr[1000][3];
int func(int x, int y)
{
	//기저 : 마지막에 도달했을때
	if (x == N - 1)return arr[x][y];

	//중복검사
	int& ret = dp[x][y];
	if (ret != -1)return ret;

	if (y == 0)
		 ret = min(func(x + 1, 1), func(x + 1, 2)) + arr[x][0];
	if (y == 1)
		 ret = min(func(x + 1, 0), func(x + 1, 2)) + arr[x][1];
	if (y == 2)
		 ret = min(func(x + 1, 0), func(x + 1, 1)) + arr[x][2];
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 3; ++j)
			scanf("%d", &arr[i][j]);

	printf("%d\n", min(func(0, 0), min(func(0, 1), func(0, 2))));
	return 0;
}