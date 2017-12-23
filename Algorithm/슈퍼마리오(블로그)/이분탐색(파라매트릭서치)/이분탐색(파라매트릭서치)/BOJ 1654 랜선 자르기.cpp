#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int K,N;
int arr[10000];
int maxN = 0;

int main()
{
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > maxN)
			maxN = arr[i];
	}

	long right = maxN;
	long left = 1;

	while (left <= right)
	{
		long mid = (left + right) / 2;
		int total = 0;
		for (int i = 0; i < K; ++i)
		{
			total += (arr[i] / mid);
		}

		if (total < N)
			right = mid - 1;
		else if (N <= total)
			left = mid + 1;
	}
	printf("%d\n", right);
}