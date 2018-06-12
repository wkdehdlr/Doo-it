#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char A[1005];
char B[1005];
char C[1005];
int dp[1005][1005];
int lenA, lenB, lenC;
int func(int a, int b)
{
	if (a == -1 || b == -1)return 0;
	int& ret = dp[a][b];
	if (ret != -1)return ret;
	//ret = 0;
	if (A[a] == B[b]) {
		ret = func(a - 1, b - 1) + 1;
	}
	else {
		ret = max(func(a, b - 1), func(a - 1, b));
	}
	return ret;
}
void LCS(int a, int b)
{
	if (a == -1 || b == -1)return;
	if (A[a] == B[b])
	{
		C[lenC--] = A[a];
		LCS(a - 1, b - 1);
	}
	else {
		if (a == 0 || b == 0) {
			a == 0 ? C[lenC] = A[a] : C[lenC] = B[b];
			return;
		}
		if (dp[a][b - 1] > dp[a - 1][b]) {
			LCS(a, b - 1);
		}
		else {
			LCS(a - 1, b);
		}
	}
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%s %s", A, B);
	lenA = strlen(A) - 1;
	lenB = strlen(B) - 1;
	lenC = func(lenA, lenB);
	printf("%d\n", lenC--);
	if (lenC != -1){
		LCS(lenA, lenB);
		printf("%s\n", C);
	}
}