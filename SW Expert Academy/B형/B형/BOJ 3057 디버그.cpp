#pragma warning(disable : 4996)
#include<cstdio>

int arr[301][301];
int R, C, maxN = 0;
bool func2(int i, int j)
{
	bool flag = false;
	for (int r = 0; r < maxN; ++r)
	{
		for (int c = 0; c < maxN; ++c)
		{
			if (i + r > i + (maxN - 1) - r || (i + r == i + (maxN - 1) - r && j + c > j + (maxN - 1) - c))
			{
				flag = true;
				break;
			}

			if (arr[i + r][j + c] != arr[i + (maxN - 1) - r][j + (maxN - 1) - c])
				return false;
		}
		if (flag)
			return true;
	}
	return true;
}
bool func()
{
	for (int i = 1; i <= R - maxN + 1; ++i)
	{
		for (int j = 1; j <= C - maxN + 1; ++j)
		{
			if (func2(i, j))//시작좌표설정
				return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	maxN = R >= C ? C : R;//정사각형이니까 더 작은놈으로 초기값 설정
	while (maxN >= 2)
	{
		if (func())
		{
			printf("%d\n", maxN);
			return 0;
		}
		--maxN;
	}
	printf("-1\n");
}