#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
using namespace std;

int dp[31][40001];
int arr[31];
int N;
int N2, tmp;
void func(int dep, int tot)
{
	if (dp[dep][tot] != 0)return;
	dp[dep][tot] = 1;
	if (dep == N)return;
	func(dep + 1, tot + arr[dep + 1]);
	func(dep + 1, abs(tot - arr[dep + 1]));
	func(dep + 1, tot);
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &arr[i]);
	}
	func(0, 0);
	scanf("%d", &N2);
	for (int i = 1; i <= N2; ++i) {
		scanf("%d", &tmp);
		if (dp[N][tmp])printf("Y ");
		else printf("N ");
	}
	printf("\n");
}
