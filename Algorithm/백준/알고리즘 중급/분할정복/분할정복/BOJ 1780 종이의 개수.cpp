#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int brr[3];
int arr[2500][2500];
void solve(int, int, int, int);
bool same(int, int, int, int);
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%d", &arr[i][j]);

	solve(0, N, 0, N);
	for (int i = 0; i < 3; ++i)
		printf("%d\n", brr[i]);
}
void solve(int xs, int xe, int ys, int ye)
{
	if (same(xs, xe, ys, ye))
	{
		;
	}
	else
	{
		solve(xs, xs + (xe - xs) / 3, ys, ys + (ye - ys) / 3);
		solve(xs, xs + (xe - xs) / 3, ys + (ye - ys) / 3, ye - (ye - ys) / 3);
		solve(xs, xs + (xe - xs) / 3, ye - (ye - ys) / 3, ye);
		solve(xs + (xe - xs) / 3, xe - (xe - xs) / 3, ys, ys + (ye - ys) / 3);
		solve(xs + (xe - xs) / 3, xe - (xe - xs) / 3, ys + (ye - ys) / 3, ye - (ye - ys) / 3);
		solve(xs + (xe - xs) / 3, xe - (xe - xs) / 3, ye - (ye - ys) / 3, ye);
		solve(xe - (xe - xs) / 3, xe, ys, ys + (ye - ys) / 3);
		solve(xe - (xe - xs) / 3, xe, ys + (ye - ys) / 3, ye - (ye - ys) / 3);
		solve(xe - (xe - xs) / 3, xe, ye - (ye - ys) / 3, ye);
	}
}
bool same(int xs, int xe, int ys, int ye)
{
	int temp = arr[xs][ys];
	for (int i = xs; i < xe; ++i)
		for (int j = ys; j < ye; ++j)
			if (temp != arr[i][j])
				return false;


	if (temp == -1)brr[0]++;
	else if (temp == 0)brr[1]++;
	else brr[2]++;
	return true;
}