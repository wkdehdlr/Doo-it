#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;
struct info {
	int walk;
	int w_money;
	int cycle;
	int c_money;
};
int N, K;
info arr[101];
int dp[101][100001];
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i){
		scanf("%d %d %d %d", &arr[i].walk, &arr[i].w_money, &arr[i].cycle, &arr[i].c_money);
	}

	if (arr[0].cycle == arr[0].walk)
	{
		dp[0][arr[0].cycle] = arr[0].c_money < arr[0].w_money ? arr[0].w_money : arr[0].c_money;
	}
	else
	{
		dp[0][arr[0].cycle] = arr[0].c_money;
		dp[0][arr[0].walk] = arr[0].w_money;
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j <= K; ++j) {
			if (dp[i - 1][j]) 
			{
				if (j + arr[i].walk <= K)
				{
					if (dp[i][j + arr[i].walk] < dp[i - 1][j] + arr[i].w_money)
						dp[i][j + arr[i].walk] = dp[i - 1][j] + arr[i].w_money;
				}

				if (j + arr[i].cycle <= K)
				{
					if(dp[i][j + arr[i].cycle] < dp[i - 1][j] + arr[i].c_money)
						dp[i][j + arr[i].cycle] = dp[i - 1][j] + arr[i].c_money;
				}
			}
		}
	}

	int mx = 0;
	for (int i = 0; i <= K; ++i) {
		if (dp[N - 1][i] > mx)
			mx = dp[N - 1][i];
	}
	printf("%d\n", mx);
}