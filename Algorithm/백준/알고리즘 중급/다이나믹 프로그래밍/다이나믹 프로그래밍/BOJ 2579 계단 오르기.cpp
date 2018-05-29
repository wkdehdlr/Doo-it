#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[301], N, dp[301];
int func(int idx)
{
	//기저사례
	if (idx < 1)return 0;
	if (idx == 1)return arr[idx];
	//메모이제이션
	int& ret = dp[idx];
 	if (ret != -1)return ret; 
	return ret = max(func(idx - 2), func(idx - 3) + arr[idx - 1]) + arr[idx];
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	printf("%d\n", func(N));
}