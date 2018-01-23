#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int N;
int arr[100000];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	int maxN = 0;
	for (int i = 0, size = N; i < size; ++i, N--)
	{
		if (N * arr[i] > maxN)
			maxN = N * arr[i];
	}
	printf("%d\n", maxN);
}