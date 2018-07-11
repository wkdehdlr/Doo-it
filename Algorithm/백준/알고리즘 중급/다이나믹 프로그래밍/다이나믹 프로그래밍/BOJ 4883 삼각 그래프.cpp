#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//typedef long long ll;
int arr[100001][4];
int dp[100001][4];
int N, t=1;
int func(int x, int y)
{
	if (x == N) {
		if (y == 1) {
			return arr[N][1] + arr[N][2];
		}
		else if (y == 2) {
			return arr[N][2];
		}
		else {//y==3
			return 987654321;
		}
	}
	int& ret = dp[x][y];
	if (ret != -1)return ret;
	ret = 987654321;

	if (y == 1) {
		return ret = min(func(x, 2), min(func(x + 1, 1), func(x + 1, 2))) + arr[x][y];
	}
	else if (y == 2) {
		return ret = min(func(x, 3), min(func(x + 1, 3), min(func(x + 1, 1), func(x + 1, 2)))) + arr[x][y];
	}
	else {//y==3
		return ret = min(func(x + 1, 2), func(x + 1, 3)) + arr[x][y];
	}
}

int main()
{
	while (1) {
		scanf("%d", &N);
		if (!N)break;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= 3; ++j) {
				scanf("%d", &arr[i][j]);
			}
		}
		/*
		dp[1][1] = arr[1][1];
		dp[1][2] = arr[1][2];
		dp[1][3] = dp[1][2] + arr[1][3];
		dp[2][1] = dp[1][2] + arr[2][1];
		dp[2][2] = min(dp[1][3], min(dp[2][1], dp[1][2])) + arr[2][2];
		dp[2][3] = min(dp[1][3], min(dp[2][2], dp[1][2])) + arr[2][3];
		for (int x = 3; x <= N; ++x) {
			for (int y = 1; y <= 3; ++y) {
				if (y == 1) {
					dp[x][y] = min(dp[x - 1][1], dp[x - 1][2]) + arr[x][y];
				}
				else if (y == 2) {
					dp[x][y] = min(dp[x - 1][3], min(dp[x - 1][2], min(dp[x][1], dp[x - 1][1]))) + arr[x][y];
				}
				else {
					dp[x][y] = min(dp[x - 1][3], min(dp[x][2], dp[x - 1][2])) + arr[x][y];
				}
			}
		}*/
		//scanf("%d", &t);
		printf("%d. %d\n", t++, func(1, 2));
	}
}