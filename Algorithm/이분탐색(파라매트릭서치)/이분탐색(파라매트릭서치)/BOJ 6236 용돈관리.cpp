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
		if (arr[i] > maxN)
			maxN = arr[i];
		right += arr[i];
	}

	int left = maxN;
	int cnt = 1;
	while (left<=right)
	{

		int mid = (left + right) / 2;
		int temp = mid;
		cnt = 1;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] <= temp)
				temp -= arr[i];
			else
			{
				temp = 0;
				while (temp < arr[i])
				{
					temp += mid;
					cnt++;
				}
				temp -= arr[i];
			}
		}

		if (cnt <= M)
			right = mid-1;
		else if (M < cnt)
			left = mid+1;
	}
	printf("%d\n", left);
}