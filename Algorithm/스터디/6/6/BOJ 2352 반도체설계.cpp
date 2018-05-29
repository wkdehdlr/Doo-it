#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int N;
int arr[40001];
int res[40001];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &arr[i]);

	int idx = 0;
	res[idx] = arr[1];
	idx++;
	for (int i = 2; i <= N; ++i)
	{
		if (res[idx - 1] < arr[i]) {
			res[idx] = arr[i];
			idx++;
		}
		else {
			*upper_bound(res, res + idx, arr[i]) = arr[i];
		}
	}
	printf("%d\n", idx);
}