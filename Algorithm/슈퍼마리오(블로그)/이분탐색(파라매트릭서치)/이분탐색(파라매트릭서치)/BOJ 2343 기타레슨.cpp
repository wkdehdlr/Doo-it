#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int N, M;
int arr[100000];

int main()
{
	int maxN = 0;
	int right = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
		if (maxN < arr[i])
			maxN = arr[i];
		right += arr[i];
	}

	int left = maxN;

	while (left<=right)
	{
		int mid = (left + right) / 2;
		int temp = 0;
		int cnt = 1;
		for (int i = 0; i < N; ++i)
		{
			temp += arr[i];
			if (temp > mid)
			{
				cnt++;
				temp = 0;
				temp += arr[i];
			}
		}

		if (cnt <= M)
			right = mid - 1;
		else if (M < cnt)
			left = mid + 1;
	}
	printf("%d\n", left);
}