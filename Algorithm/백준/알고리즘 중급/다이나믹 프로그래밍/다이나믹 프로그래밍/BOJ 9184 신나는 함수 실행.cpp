#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int dp[21][21][21];
int a, b, c;
int w(int x, int y, int z)
{
	if (x >= 0 && x < 21 && y >= 0 && y < 21 && z >= 0 && z < 21) {
		int& ret = dp[x][y][z];
		if (ret != -1)return ret;

		if (x <= 0 || y <= 0 || z <= 0) {
			//w(x, y, z);
			return ret = 1;
		}

		if (x > 20 || y > 20 || z > 20) {
			//w(x, y, z);
			return ret = w(20, 20, 20);
		}
		if (x < y && y < z) {
			//w(x, y, z);
			return ret = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
		}

		return ret = w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);
	}
	else {
		if (x <= 0 || y <= 0 || z <= 0) {
			//w(x, y, z);
			return 1;
		}

		if (x > 20 || y > 20 || z > 20) {
			//w(x, y, z);
			return w(20, 20, 20);
		}
		if (x < y && y < z) {
			//w(x, y, z);
			return w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
		}

		return w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);
	}
}
int main()
{
	memset(dp, -1, sizeof(dp));
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1)return 0;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
}