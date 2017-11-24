#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int col[11];
int T, N;
int cnt;

void func(int);
int check(int, int);
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		memset(col, 0, sizeof(int) * 11);
		cnt = 0;
		scanf("%d", &N);
		func(1);
		printf("#%d %d\n", tc + 1, cnt);
	}
}
void func(int x)
{
	if (x == N + 1)
	{
		cnt++;
	}
	else
	{
		for (int j = 1; j <= N; ++j)
		{
			if (check(x, j))
			{
				col[j] = x;
				func(x + 1);
				col[j] = 0;
			}
		}
	}
}
int check(int i, int j)
{
	if (col[j] == 0)
	{
		for (int k = 1; k <= N; ++k)
		{
			if (abs(k - j) == abs(col[k] - i) && col[k])
				return 0;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}