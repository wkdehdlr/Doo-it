#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int arr[1010];
int dp[501][501];
void my_scanf()
{
	int tmp, idx = 2;
	scanf("%d", &N);
	scanf("%d", &arr[0]);
	scanf("%d", &arr[1]);
	for (int i = 1; i <= 2 * (N - 1); ++i) {
		scanf("%d", &tmp);scanf("%d", &tmp);
		arr[idx++] = tmp;
	}
}
int func(int f, int e)
{
	if (f == e)return 0;
	int& ret = dp[f][e];
	if (ret != -1)return ret;
	ret = 987654321;
	for (int i = f; i < e; ++i) {
		ret = min(ret, func(f, i) + func(i + 1, e) + arr[f - 1] * arr[i] * arr[e]);
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	my_scanf();
	printf("%d\n", func(1, N));
}