#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int i, n, j = 0;
int cnt = 0;
int lis[1001];
int arr[1001];

int main()
{
	scanf("%d", &n);

	for (i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	i = 0;

	lis[i] = arr[i];
	i++;

	while (i < n)
	{
		if (lis[j] < arr[i])
		{
			lis[j + 1] = arr[i];
			j++;
		}
		else
		{
			lis[lower_bound(lis, lis + j, arr[i]) - lis] = arr[i];
		}

		i++;
	}
	printf("%d\n", j + 1);
}