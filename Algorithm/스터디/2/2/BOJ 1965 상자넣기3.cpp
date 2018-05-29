#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
#include<cstring>

int dp[1001];
int arr[1001];
int N;
int lis(int start)
{
	int& ret = dp[start + 1];
	if (ret != -1)return ret;

	ret = 1;
	for (int next = start + 1; next < N; ++next)
	{
		if (start == -1 || arr[start] < arr[next])
			ret = std::max(ret, 1 + lis(next));
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);

	printf("%d\n", lis(-1) - 1);
}