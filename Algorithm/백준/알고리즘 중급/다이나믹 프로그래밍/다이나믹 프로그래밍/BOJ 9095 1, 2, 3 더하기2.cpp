#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
int N, T;
int dp[12];
int func(int n)
{
	//�������
	if (n == 11)return 1;
	if (n > 11)return 0;
	//�޸������̼�
	int& ret = dp[n];
	if (ret != -1)return ret;
	return ret = func(n + 1) + func(n + 2) + func(n + 3);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	func(0);
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		printf("%d\n", dp[11 - N]);
	}
}