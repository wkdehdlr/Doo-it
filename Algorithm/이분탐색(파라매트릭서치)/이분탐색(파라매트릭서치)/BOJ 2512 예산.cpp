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
	int left = 1;

	while (left<=right)
	{
		int mid = (left + right) / 2;
		int total = 0;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] < mid)
				total += arr[i];
			else
				total += mid;
		}

		if (total <= M)
			left = mid+1;
		else if (M < total)
			right = mid-1;
	}
	printf("%d\n", right);
}