#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int N, M, T;
int arr[31];
int dp[31][31];
int func(int n,int k)
{
	//기저사례
	if (k == N)return 1;
	//메모이제이션
	int& ret = dp[n][k];
	if (ret != -1)return ret;
	ret = 0;
	for (int j = n + 1; j <= M; ++j) {
		if (arr[n] < arr[j]) {
			ret += func(j, k + 1);
		}
	}
	return ret;
}
int main()
{
	for (int i = 1; i <= 30; ++i)arr[i] = i;
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		memset(dp, -1, sizeof(dp));
		scanf("%d %d", &N, &M);
		int ret = 0;
		for (int i = 1; i <= M; ++i)ret += func(i, 1);
		printf("%d\n", ret);
	}
}