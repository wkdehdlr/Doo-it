#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int arr[10001];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	if (next_permutation(arr, arr + n))
		for (int i = 0; i < n; ++i)
			printf("%d ", arr[i]);
	else
		printf("-1\n");		
}