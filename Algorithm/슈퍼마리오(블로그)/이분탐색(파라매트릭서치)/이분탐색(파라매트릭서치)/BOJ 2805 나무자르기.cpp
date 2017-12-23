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
	int left = 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		long long total = 0;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] > mid)
				total += (arr[i] - mid);
		}

		if (total < M)
			right = mid - 1;
		else if (M <= total)
			left = mid + 1;
	}

	printf("%lld\n", right);
}