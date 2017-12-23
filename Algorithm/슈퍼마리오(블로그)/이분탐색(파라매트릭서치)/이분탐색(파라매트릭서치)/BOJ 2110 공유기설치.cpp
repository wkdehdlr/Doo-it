#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int N, C;
int arr[200000];

void quickSort(int first, int last)
{
	int pivot;
	int i;
	int j;
	int temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (arr[i] <= arr[pivot] && i < last)
			{
				i++;
			}
			while (arr[j] > arr[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}

void insertionSort(void)
{
	int temp;
	int i;
	int j;

	for (i = 1; i < N; i++)
	{
		temp = arr[i];
		j = i - 1;

		while ((temp < arr[j]) && (j >= 0))
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

int main()
{
	int maxN = 0;
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > maxN)
			maxN = arr[i];
	}
	insertionSort();
	//sort(arr, arr + N);
	//quickSort(0, N - 1);//일단 정렬
	int right = maxN;
	int left = 1;
	bool flag = false;
	int cnt = 1;
	int dis;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		cnt = 1;
		dis = arr[0];
		for (int i = 1; i < N; ++i)
		{
			if (dis + mid <= arr[i])
			{
				cnt++;
				dis = arr[i];
			}
		}

		if (cnt < C)
			right = mid-1;
		else if (C <= cnt)
			left = mid+1;
	}
	printf("%d\n", right);
}