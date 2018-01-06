#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int arr[64][64];
int N;

bool same(int x, int y, int n)
{
	int tmp = arr[x][y];
	for (int i = x; i < x + n; ++i)
		for (int j = y; j < y + n; j++)
			if (tmp != arr[i][j])
				return false;

	if (tmp)printf("1");
	else printf("0");
	return true;
}
void solve(int x, int y, int n)
{
	if (same(x, y, n))
		;
	else
	{
		printf("(");
		int m = n / 2;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; j++)
				solve(x + m*i, y + m*j, m);
		printf(")");
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%1d", &arr[i][j]);

	solve(0, 0, N);
}