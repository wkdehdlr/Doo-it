#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> cookie = { 1,2,4,5 };
int dp[2001][2001];
int main()
{
	int size = cookie.size();
	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			if (j == 0)dp[i][j] = cookie[j];
			else dp[i][j] = dp[i][j - 1] + cookie[j];
		}
	}
	int mx = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			for (int k = j + 1; k < size; ++k) {
				if (dp[i][j] == dp[j + 1][k]) {
					mx = max(mx, dp[i][j]);
				}
				else if (dp[i][j] < dp[j + 1][k])break;
			}
		}
	}
	printf("%d\n", mx);
}