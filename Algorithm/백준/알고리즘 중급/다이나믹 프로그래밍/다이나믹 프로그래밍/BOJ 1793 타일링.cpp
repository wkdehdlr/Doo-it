#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
int N;
char dp[251][1000];
void func(int n)
{
	char tmp[1000] = { '\0', };
	int len = strlen(dp[n - 2]);
	bool carry = false;
	for (int i = 0; i < len; ++i) {
		int res = dp[n - 2][i] - '0';
		if (res >= 5) {
			if (carry)tmp[i] = ((res * 2) % 10) + 1 + '0';
			else tmp[i] = ((res * 2) % 10) + '0';
			carry = true;
		}
		else {
			if (carry)tmp[i] = (res * 2) + 1 + '0';
			else tmp[i] = (res * 2) + '0';
			carry = false;
		}
	}
	if (carry)tmp[len] = '1';


	len = strlen(dp[n - 1]);
	int len2 = strlen(tmp);
	carry = false;
	int i = 0;
	for (; i < len && i < len2; ++i) {
		int res1 = dp[n - 1][i] - '0';
		int res2 = tmp[i] - '0';
		int res = res1 + res2;
		if (carry)res += 1;
		if (res >= 10) {
			dp[n][i] = (res - 10) + '0';
			carry = true;
		}
		else {
			dp[n][i] = res + '0';
			carry = false;
		}
	}
	for (int j = i; j < len; ++j) {
		int res = dp[n - 1][j] - '0';
		if (carry)res += 1;
		if (res >= 10) {
			dp[n][j] = (res - 10) + '0';
			carry = true;
		}
		else {
			dp[n][j] = res + '0';
			carry = false;
		}
	}
	for (int j = i; j < len2; ++j) {
		int res = tmp[j] - '0';
		if (carry)res += 1;
		if (res >= 10) {
			dp[n][j] = (res - 10) + '0';
			carry = true;
		}
		else {
			dp[n][j] = res + '0';
			carry = false;
		}
	}
	if (carry)dp[n][i] = '1';
}
int main()
{
	strcpy(dp[0], "1");
	strcpy(dp[1], "1");
	strcpy(dp[2], "3");
	for (int i = 3; i <= 250; ++i) {
		func(i);
	}
	while (~scanf("%d", &N)) {
		int len = strlen(dp[N]);
		for (int i = len - 1; i >=0; --i)
			printf("%c", dp[N][i]);
		printf("\n");
	}
}