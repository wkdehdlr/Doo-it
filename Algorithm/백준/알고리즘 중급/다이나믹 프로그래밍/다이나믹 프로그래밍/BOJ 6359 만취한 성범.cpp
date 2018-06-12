#include<cstdio>

int N, T;
int arr[101];
int dp[101];
int main()
{
	for (int i = 1; i <= 100; ++i)arr[i] = 1;

	for (int i = 2; i <= 100; ++i) {
		for (int j = i; j <= 100; j += i) {
			if (arr[j] == 1)arr[j] = 0;
			else arr[j] = 1;
		}
	}

	for (int i = 1; i <= 100; ++i)
	{
		dp[i] = dp[i - 1] + arr[i];
	}
	scanf("%d", &T);
	for (int tc = 0; tc<T; ++tc) {
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
}