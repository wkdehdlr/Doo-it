#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
using namespace std;

int N, T;
int arr[100001];
int tmp[100001];

int main()
{
	scanf("%d %d", &N, &T);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}
	int left = 0;
	int right = 2000000000;
	int mid = 0;
	int cnt = 0;
	while (left <= right)
	{
		cnt = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < N; ++i)tmp[i] = arr[i];
		for (int i = 0; i < N - 1; ++i)
		{
			if (tmp[i] + mid < tmp[i + 1])
			{
				cnt += tmp[i + 1] - (tmp[i] + mid);
				tmp[i + 1] -= (tmp[i + 1] - (tmp[i] + mid));
			}
		}

 		for (int i = N - 1; i > 0; --i)
		{
			if (tmp[i] + mid < tmp[i - 1])
			{
				cnt += tmp[i - 1] - (tmp[i] + mid);
				tmp[i - 1] -= (tmp[i - 1] - (tmp[i] + mid));
			}
		}

		if (cnt <= T)
		{
			right = mid - 1;
		}
		else if (cnt > T)
		{
			left = mid + 1;
		}
	}

	for (int i = 0; i < N; ++i)tmp[i] = arr[i];
	for (int i = 0; i < N - 1; ++i)
	{
		if (tmp[i] + left < tmp[i + 1])
		{
			tmp[i + 1] -= (tmp[i + 1] - (tmp[i] + left));
		}
	}

	for (int i = N - 1; i > 0; --i)
	{
		if (tmp[i] + left < tmp[i - 1])
		{
			tmp[i - 1] -= (tmp[i - 1] - (tmp[i] + left));
		}
	}

	for (int i = 0; i < N; ++i)
	{
		printf("%d ", tmp[i]);
	}
}