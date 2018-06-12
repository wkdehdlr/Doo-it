#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, K;
int dp[10001];
int arr[101];
int func(int k)
{
	//±âÀú»ç·Ê
	if (k == 0)return 0;

	int& ret = dp[k];
	if (ret != -1)return ret;

	ret = 987654321;
	for (int i = 1; i <= N; ++i) {
		if (k >= arr[i])
			ret = min(ret, func(k - arr[i]));
	}
	return ret += 1;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	int ret = func(K);
	if (ret == 987654322)
		printf("-1\n");
	else printf("%d\n", ret);
}