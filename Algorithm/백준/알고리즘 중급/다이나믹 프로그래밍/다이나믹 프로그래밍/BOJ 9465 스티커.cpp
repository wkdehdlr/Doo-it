#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[3][100001];
int arr[3][100001];
int N, T;
int func(int x, int y)
{
	if (y > N)return 0;
	if (y == N)return arr[x][y];
	int& ret = dp[x][y];
	if (ret != -1)return ret;

	if (x == 1)
		return ret = max(func(2, y + 1), func(2, y + 2)) + arr[x][y];
	if (x == 2)
		return ret = max(func(1, y + 1), func(1, y + 2)) + arr[x][y];
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		memset(dp, -1, sizeof(dp));
		scanf("%d", &N);
		for (int i = 1; i <= 2; ++i) 
			for (int j = 1; j <= N; ++j) 
				scanf("%d", &arr[i][j]);
		printf("%d\n", max(func(1, 1), func(2, 1)));
	}
}