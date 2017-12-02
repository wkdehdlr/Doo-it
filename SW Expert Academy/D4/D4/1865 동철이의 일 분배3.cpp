#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;
int mat[3][3];
int dp[3][2][2][2];

double go(int, int, int, int);
int main()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%lf\n", go(0, 0, 0, 0));
}
double go(int degree, int one, int two, int three)
{
	if (degree == 2) {
		if (!one)return mat[2][0];
		else if (!two)return mat[2][1];
		else return mat[2][2];
	}

	if (dp[degree][one][two][three] != -1)return dp[degree][one][two][three];
	double temp, max = 0;

	if (!one) {
		temp = mat[degree][0] * go(degree + 1, 1, two, three);
		if (temp > max)max = temp;
	}
	if (!two) {
		temp = mat[degree][1] * go(degree + 1, one, 1, three);
		if (temp > max)max = temp;
	}
	if (!three) {
		temp = mat[degree][2] * go(degree + 1, one, two, 1);
		if (temp > max)max = temp;
	}

	return dp[degree][one][two][three] = max;
}