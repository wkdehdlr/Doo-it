#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>

int arr[501];
int sum[501];
int N, K;
double mn = 987654321;
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &arr[i]);
		sum[i] += arr[i] + sum[i - 1];;
	}

	for (int i = 1; i <= N; ++i) {
		for (int k = K; k + i - 1 <= N; ++k) {
			double m = (double)((double)(sum[i + k - 1] - sum[i - 1]) / (double)k);

			double cnt = 0;
			for (int j = 0; j < k; ++j) {
				cnt += pow((double)arr[j + i] - m, 2);
			}
			double res = sqrt((double)(double)cnt / (double)k);
			if (res < mn)
				mn = res;
		}
	}
	printf("%.11lf\n", mn);
}