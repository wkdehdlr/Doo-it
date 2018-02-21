#pragma warning(disable : 4996)
#include<cstdio>

char arr[301][301];
int R, C, maxN = 0;

bool func2(int i, int j)
{
	bool flag = false;
	for (int r = 0; r < maxN; ++r)
	{
		int tr1 = i + r;
		int tr2 = i + (maxN - 1) - r;
		for (int c = 0; c < maxN; ++c)
		{
			int tc1 = j + c;
			int tc2 = j + (maxN - 1) - c;
			if (tr1 > tr2 || (tr1 == tr2 && tc1 > tc2))
			{
				flag = true;
				break;
			}

			if (arr[tr1][tc1] != arr[tr2][tc2])
				return false;
		}
		if (flag)
			return true;
	}
	return true;
}
bool func()
{
	int r = R - maxN + 1;
	int c = C - maxN + 1;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
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
	for (int i = 0; i < R; ++i)
	{
		scanf("%s", arr[i]);
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