#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int mat[16][16];
double dp[16][65546];
double go(int, int);
int T, N;
double res;
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				scanf("%d", &mat[i][j]);
			}
		}
		int k = pow(2, N);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < k; ++j)
				dp[i][j] = -1.0;

		printf("#%d %lf\n", tc + 1, go(0, 0) * 100);
	}
}
double go(int degree, int one)
{
	if (degree == N-1) {
		for (int i = N-1; i >= 0; --i)
		{
			if (!(one & (1 << i)))
			{
				return (double)mat[N - 1][N - 1 - i] * 0.01;
			}
		}
	}
	if (dp[degree][one] != -1.0)return dp[degree][one];
	double temp, max = 0;
	int one_temp = 0;

	for (int i = N-1; i >= 0; --i)
	{
		if (!(one & (1 << i)))
		{
			one_temp = one;
			temp = 0.01 * (double)mat[degree][N-1 - i] * go(degree + 1, one_temp |= (1 << i));
			if (temp > max)max = temp;
		}
	}
	return dp[degree][one] = max;
}