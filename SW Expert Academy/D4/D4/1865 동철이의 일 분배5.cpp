#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;
int mat[5][5];
long long dp[5][16];
double go(int, int);

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			scanf("%lld", &mat[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%lf\n", go(0, 0));
}
double go(int degree, int one)
{
	if (degree == 4) {
		for (int i = 4; i >= 0; --i)
		{
			if (!(one & (1 << i)))
			{
				return mat[4][4 - i];
			}
		}
	}
	if (dp[degree][one] != -1)return dp[degree][one];
	double temp, max = 0;
	int one_temp = 0;

	for (int i = 4; i >= 0; --i)
	{
		if (!(one & (1 << i))) 
		{
			one_temp = one;
			temp = mat[degree][4 - i] * go(degree + 1, one_temp |= (1 << i));
			if (temp > max)max = temp;
		}
	}
	return dp[degree][one] = max;
}