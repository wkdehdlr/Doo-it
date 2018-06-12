#include<cstdio>
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#define max(a,b)    (((a) > (b)) ? (a) : (b))
int N;
int arr[3];
int dp[2][3];
int temp[2][3];
int main()
{
	scanf("%d", &N);
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	dp[0][0] = arr[0]; dp[0][1] = arr[1]; dp[0][2] = arr[2];
	dp[1][0] = arr[0]; dp[1][1] = arr[1]; dp[1][2] = arr[2];
	for (int i = 2; i <= N; ++i) {
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		temp[0][0] = arr[0] + max(dp[0][0], dp[0][1]);
		temp[0][1] = arr[1] + max(max(dp[0][0], dp[0][1]), dp[0][2]);
		temp[0][2] = arr[2] + max(dp[0][1], dp[0][2]);

		temp[1][0] = arr[0] + min(dp[1][0], dp[1][1]);
		temp[1][1] = arr[1] + min(min(dp[1][0], dp[1][1]), dp[1][2]);
		temp[1][2] = arr[2] + min(dp[1][1], dp[1][2]);

		dp[0][0] = temp[0][0];
		dp[0][1] = temp[0][1];
		dp[0][2] = temp[0][2];

		dp[1][0] = temp[1][0];
		dp[1][1] = temp[1][1];
		dp[1][2] = temp[1][2];
	}
	printf("%d %d\n", max(max(dp[0][0], dp[0][1]), dp[0][2]), min(min(dp[1][0], dp[1][1]), dp[1][2]));
}