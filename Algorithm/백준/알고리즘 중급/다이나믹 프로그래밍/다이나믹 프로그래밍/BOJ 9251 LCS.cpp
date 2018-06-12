#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char A[1001];
char B[1001];
int lenA, lenB;
int dp[1001][1001];
int func(int a, int b)
{
	if (a == lenA || b == lenB)return 0;
	int& ret = dp[a][b];
	if (ret != -1)return ret;
	for (int i = a; i < lenA; ++i) {
		for (int j = b; j < lenB; ++j) {
			if (A[i] == B[j]) {
				ret = max(ret, func(i + 1, j + 1));
				break;
			}
		}
	}
	return ret += 1;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%s %s", A, B);
	lenA = strlen(A);
	lenB = strlen(B);
	printf("%d\n", func(0, 0));
}
