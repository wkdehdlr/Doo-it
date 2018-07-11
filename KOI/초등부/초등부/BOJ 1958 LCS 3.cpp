#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char A[110];
char B[110];
char C[110];
int lenA, lenB, lenC;
int dp[110][110][110];
int func(int a, int b, int c)
{
	if (a == -1 || b == -1 || c == -1)return 0;
	int& ret = dp[a][b][c];
	if (ret != -1)return ret;
	ret = 0;
	if (A[a] == B[b] && B[b] == C[c])
		ret = func(a - 1, b - 1, c - 1) + 1;
	else {
		ret = max(ret, func(a - 1, b, c));
		ret = max(ret, func(a, b - 1, c));
		ret = max(ret, func(a, b, c - 1));
	}
	return ret;
}
int main()
{	
	memset(dp, -1, sizeof(dp));
	scanf("%s %s %s", A, B, C);
	lenA = strlen(A) - 1; lenB = strlen(B) - 1; lenC = strlen(C) - 1;
	printf("%d\n", func(lenA, lenB, lenC));
}