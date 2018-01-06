#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;


char arr[6144][6144];
void solve(int x, int y, int n)
{
	if (n == 3)
	{	
		for (int i = x; i < x + 3; ++i)
		{
			for (int j = y; j < y + 5; ++j)
			{
				if (i == x && j == y + 2)
				{
					arr[i][j] = '*'; continue;
				}
				if ((i == x + 1 && j == y + 1) || (i == x + 1 && j == y + 3))
				{
					arr[i][j] = '*'; continue;
				}
				if (i == x + 2)
				{
					arr[i][j] = '*'; continue;
				}
			}
		}
	}
	else
	{
		int m = n / 2;
		solve(x, y + m, m);
		solve(x + m, y, m);
		solve(x + m, y + n, m);
	}
}
int main()
{
	memset(arr, ' ', sizeof(arr));

	int n;
	scanf("%d", &n);
	solve(0, 0, n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2 * n; ++j)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}