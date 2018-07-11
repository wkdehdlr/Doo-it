#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

char A[25];
char B[105];
char C[105];
int lenA, lenB, lenC;
int dp[2][101][21];
int func(int bc,int idx, int ch)
{
	if (idx < 0 && ch >= 0)return 0;
	if (ch < 0)return 1;
	int& ret = dp[bc][idx][ch];
	if (ret != -1)return ret;

	ret = 0;
	if (bc) {
		for (int i = idx; i >= 0; --i) {
			if (A[ch] == C[i]) {
				ret += func(0, i - 1, ch - 1);
			}
		}
	}
	else {
		for (int i = idx; i >= 0; --i) {
			if (A[ch] == B[i]) {
				ret += func(1, i - 1, ch - 1);
			}
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%s %s %s", A, B, C);
	lenA = strlen(A);
	lenB = strlen(B);
	lenC = strlen(C);
	int ret = 0;
	for (int i = lenB - 1; i >= 0; --i) {
		if (A[lenA - 1] == B[i]) {
			ret += func(1, i - 1, lenA - 2);
		}
	}

	for (int i = lenC - 1; i >= 0; --i) {
		if (A[lenA - 1] == C[i]) {
			ret += func(0, i - 1, lenA - 2);
		}
	}
	printf("%d\n", ret);
}