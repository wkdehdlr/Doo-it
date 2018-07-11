#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int dp[4010][4010];
char A[4010];
char B[4010];
int lenA;
int lenB;
int func(int a, int b)
{
	if (a == -1 || b == -1)return 0;
	int&ret = dp[a][b];
	if (ret != -1)return ret;

	if (A[a] == B[b])
		return ret = func(a - 1, b - 1) + 1;
	else
		return ret = 0;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%s %s", A, B);
	lenA = strlen(A);
	lenB = strlen(B);
	int ret = 0;
	for (int a = 0; a < lenA; ++a) {
		for (int b = 0; b < lenB; ++b) {
			ret = max(ret, func(a, b));
		}
	}
	printf("%d\n", ret);
}