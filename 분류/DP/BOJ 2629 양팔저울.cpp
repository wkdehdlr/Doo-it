#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
int dp[31][150001];
int N, M, arr[31];
void func(int idx, int left, int right)
{
	int res = abs(left - right);
	if (idx > N)return;
	if (dp[idx][res] != -2) return;

	dp[idx][res] = 1;

	func(idx + 1, left + arr[idx], right);
	func(idx + 1, left, right + arr[idx]);
	func(idx + 1, left, right);
}
void init()
{
	for (int i = 0; i < 31; ++i)
		for (int j = 0; j < 150001; ++j)
			dp[i][j] = -2;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)scanf("%d", &arr[i]);
	init();
	func(0, 0, 0);

	scanf("%d", &M);
	int tmp;
	for (int i = 0; i < M; ++i) {
		scanf("%d", &tmp);
		if (dp[N][tmp] == 1) {
			printf("Y ");
		}
		else {
			printf("N ");
		}
	}
}