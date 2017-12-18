#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int arr[1000];
int N;
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
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}

	//quickSort(0, N - 1);
	//sort(arr, arr + N);
	insertionSort();

	for (int i = 0; i < N; ++i)
	{
		printf("%d\n", arr[i]);
	}
}