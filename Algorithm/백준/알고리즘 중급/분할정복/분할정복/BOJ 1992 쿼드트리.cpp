#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int arr[64][64];
int N;

bool same(int xs, int xe, int ys, int ye)
{
	int tmp = arr[xs][ys];
	for (int i = xs; i < xe; ++i)
		for (int j = ys; j < ye; j++)
			if (tmp != arr[i][j])
				return false;

	if (tmp)printf("1");
	else printf("0");
	return true;
}
void solve(int xs, int xe, int ys, int ye)
{
	if (same(xs, xe, ys, ye))
		;
	else
	{
		printf("(");
		solve(xs, xs + (xe - xs) / 2, ys, ys + (ye - ys) / 2);
		solve(xs, xs + (xe - xs) / 2, ys + (ye - ys) / 2, ye);
		solve(xs + (xe - xs) / 2, xe, ys, ys + (ye - ys) / 2);
		solve(xs + (xe - xs) / 2, xe, ys + (ye - ys) / 2, ye);
		printf(")");
	}
}

int main()
{	
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%1d", &arr[i][j]);

	solve(0, N, 0, N);
}