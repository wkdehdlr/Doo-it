#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int N;
long long M;
long long arr[1000001];
long long maxN = 0;

int main()
{
	scanf("%d %lld", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lld", &arr[i]);
		if (maxN < arr[i])
			maxN = arr[i];
	}

	int right = maxN;
	int left = 0;
	int mid = right;

	while (1)
	{
		long long total = 0;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] > mid)
				total += (arr[i] - mid);
		}

		if (total < M)
			right = mid;
		else if (M <= total)
			left = mid;

		mid = (right + left) / 2;
		if (mid == left)
			break;
	}

	printf("%lld\n", mid);
}