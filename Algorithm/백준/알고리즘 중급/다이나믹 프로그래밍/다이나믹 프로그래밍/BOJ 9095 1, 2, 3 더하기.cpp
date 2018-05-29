#pragma warning(disable : 4996)
#include<cstdio>
int N, T;
int dp[12];
void func(int n)
{
	//±âÀú»ç·Ê
	if (n > 11)return;
	dp[n]++;
	if (n == 11) {
		return;
	}
	func(n + 1);
	func(n + 2);
	func(n + 3);
}
int main()
{
	func(0);
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
}