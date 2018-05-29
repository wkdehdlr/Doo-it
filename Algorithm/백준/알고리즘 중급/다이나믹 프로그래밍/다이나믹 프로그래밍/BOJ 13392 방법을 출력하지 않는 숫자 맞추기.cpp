#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int src[10001];
int dst[10001];
int dp[10001][11];
int func(int n, int rot)
{
	int new_src = (src[n] + rot) % 10;
	int rot_left = dst[n] > new_src ? dst[n] - new_src : (dst[n] - new_src + 10) % 10;
	int rot_right = new_src > dst[n] ? new_src - dst[n] : (new_src - dst[n] + 10) % 10;
	//기저사례
	if (n == N)return min(rot_left, rot_right);
	//메모이제이션
	int& ret = dp[n][rot];
	if (ret != -1)return ret;
	return ret = min(func(n + 1, (rot + rot_left) % 10) + rot_left, func(n + 1, rot) + rot_right);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%1d", &src[i]);
	for (int i = 1; i <= N; ++i)scanf("%1d", &dst[i]);
	printf("%d\n", func(1, 0));
}