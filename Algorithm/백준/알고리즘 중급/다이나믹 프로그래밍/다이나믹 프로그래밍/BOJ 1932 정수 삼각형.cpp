#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int dp[501][501];
int arr[501][501];

int func(int x, int y)
{
	if (x == N)return arr[x][y];
	int& ret = dp[x][y];
	if (ret != -1)return ret;
	ret = 0;
	if (y == 1)
		return ret = max(func(x + 1, 1), func(x + 1, 2)) + arr[x][y];
	if (y == x)
		return ret = max(func(x + 1, y), func(x + 1, y + 1)) + arr[x][y];
	return ret = max(func(x + 1, y), func(x + 1, y + 1)) + arr[x][y];
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}

	printf("%d\n", func(1, 1));
}