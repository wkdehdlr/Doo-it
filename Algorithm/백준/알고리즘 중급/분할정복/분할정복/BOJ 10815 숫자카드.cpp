#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int N, M;
int arr[500000];
int solve(int);
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int temp;
		scanf("%d", &temp);
		printf("%d ", solve(temp));
	}
}
int solve(int temp)
{
	int left = 0, right = N - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == temp)
			return 1;

		if (temp < arr[mid])
			right = mid - 1;
		else if (arr[mid] < temp)
			left = mid + 1;
	}
	return 0;
}