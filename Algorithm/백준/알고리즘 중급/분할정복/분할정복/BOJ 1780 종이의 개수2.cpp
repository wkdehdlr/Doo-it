#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int brr[3];
int arr[2500][2500];
void solve(int, int, int);
bool same(int, int, int);
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%d", &arr[i][j]);

	solve(0, 0, N);
	for (int i = 0; i < 3; ++i)
		printf("%d\n", brr[i]);
}
void solve(int x, int y, int n)
{
	if (same(x, y, n))
	{
		;
	}
	else
	{
		int m = n / 3;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				solve(x + m*i, y + m*j, m);
	}
}
bool same(int x, int y, int n)
{
	int temp = arr[x][y];
	for (int i = x; i < x + n; ++i)
		for (int j = y; j < y + n; ++j)
			if (temp != arr[i][j])
				return false;


	if (temp == -1)brr[0]++;
	else if (temp == 0)brr[1]++;
	else brr[2]++;
	return true;
}