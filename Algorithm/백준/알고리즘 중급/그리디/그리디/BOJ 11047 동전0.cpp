#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int N, K;
int arr[11];

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[N - i]);
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (K / arr[i])
		{
			ans += (K / arr[i]);
			K %= arr[i];
		}
	}
	printf("%d\n", ans);
}