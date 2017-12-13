#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int N,M;
int arr[10000];
int maxN = 0;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
		if (maxN < arr[i])
			maxN = arr[i];
	}
	scanf("%d", &M);

	int right = maxN;
	int left = 0;
	int mid = right;

	while (1)
	{
		int total = 0;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] <= mid)
				total += arr[i];
			else
				total += mid;
		}

		if (M < total)
			right = mid;
		else if (total <= M)
			left = mid;

		mid = (right + left) / 2;
		if (mid == left)
			break;
	}
	printf("%d\n", mid);
}