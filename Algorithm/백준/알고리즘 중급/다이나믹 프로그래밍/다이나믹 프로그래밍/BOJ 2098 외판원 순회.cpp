#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int arr[17][17];
int dp[17][1 << 17];
int func(int now, int visit)
{
	//规巩捞 场车阑版快
	if (visit  == ((1 << N) - 1)) {
		if (arr[now][0])return arr[now][0];
		else return 0x3f3f3f3f;
	}

	int& ret = dp[now][visit];
	if (ret != -1)return ret;
	ret = 0x3f3f3f3f;
	for (int i = 0; i < N; ++i)
	{
		if (arr[now][i] && !(visit & (1 << i))) {
			ret = min(ret, func(i, visit | (1 << i)) + arr[now][i]);
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%d", &arr[i][j]);
	printf("%d\n", func(0, 1));
}