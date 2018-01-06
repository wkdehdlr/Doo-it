#pragma warning(disable : 4996)
#include<cstdio>
//using namespace std;
char arr[6600][6600];

void solve(int x, int y, int n)
{
	if (n == 1)
	{
		arr[x][y] = '*';

	}
	else
	{
		int m = n / 3;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
			{
				if (i == 1 && j == 1)
					;//solve(x + m*i, y + m*j, m, BLANK);
				else
					solve(x + m*i, y + m*j, m);
			}
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			arr[i][j] = ' ';

	solve(0, 0, N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}