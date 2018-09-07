#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int trace[1001];
int N, W;
int arr[1001][3];
int dp[1001][1001];

int func3(int from, int to)//두번째 경찰차
{
	if (!from)return abs(arr[to][1] - N) + abs(arr[to][2] - N);
	return abs(arr[to][1] - arr[from][1]) + abs(arr[to][2] - arr[from][2]);
}
int func2(int from, int to)//첫번째 경찰차
{
	if (!from)return abs(arr[to][1] - 1) + abs(arr[to][2] - 1);
	return abs(arr[to][1] - arr[from][1]) + abs(arr[to][2] - arr[from][2]);
}
void trc(int x, int y)
{
	int z = max(x, y) + 1;
	if (z == W) {
		if (dp[x][y] == func2(x, z)) {
			printf("1\n");
			return;
		}

		if (dp[x][y] == func3(y, z)) {
			printf("2\n");
			return;
		}
	}
	if (dp[x][y] - func2(x, z) == dp[z][y]) {
		printf("1\n");
		trc(z, y);
		return;
	}

	if (dp[x][y] - func3(y, z) == dp[x][z]) {
		printf("2\n");
		trc(x, z);
	}
}
int func(int one, int two)
{
	if (one == W || two == W)return 0;
	int& ret = dp[one][two];
	if (ret != -1)return ret;
	return ret = min(func(max(one, two) + 1, two) + func2(one, max(one, two) + 1), func(one, max(one, two) + 1) + func3(two, max(one, two) + 1));

}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &W);
	for (int i = 1; i <= W; ++i)scanf("%d %d", &arr[i][1], &arr[i][2]);
	printf("%d\n", func(0, 0));
	trc(0,0);
}