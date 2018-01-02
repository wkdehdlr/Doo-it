#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;
struct info {
	int x, y;
}; 
info arr[1050000];
int cnt = 0;
void solve(int, int, int);
int main()
{
	int N;
	scanf("%d", &N);
	solve(N, 1, 3);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i)
		printf("%d %d\n", arr[i].x, arr[i].y);
}
void solve(int n,int x, int y)
{
	if (!n)return;
	solve(n - 1, x, 6 - x - y);
	arr[cnt].x = x;	arr[cnt++].y = y;
	solve(n - 1, 6 - x - y, y);
}