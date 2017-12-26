#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int N;
int arr_plus[10000];
int arr_minus[10000];
void quickSort_m(int first, int last)
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
			while (arr_minus[i] <= arr_minus[pivot] && i < last)
			{
				i++;
			}
			while (arr_minus[j] > arr_minus[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = arr_minus[i];
				arr_minus[i] = arr_minus[j];
				arr_minus[j] = temp;
			}
		}

		temp = arr_minus[pivot];
		arr_minus[pivot] = arr_minus[j];
		arr_minus[j] = temp;

		quickSort_m(first, j - 1);
		quickSort_m(j + 1, last);
	}
}
void quickSort_p(int first, int last)
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
			while (arr_plus[i] >= arr_plus[pivot] && i < last)
			{
				i++;
			}
			while (arr_plus[j] < arr_plus[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = arr_plus[i];
				arr_plus[i] = arr_plus[j];
				arr_plus[j] = temp;
			}
		}

		temp = arr_plus[pivot];
		arr_plus[pivot] = arr_plus[j];
		arr_plus[j] = temp;

		quickSort_p(first, j - 1);
		quickSort_p(j + 1, last);
	}
}
int main()
{
	int temp;
	int idx_p = 0, idx_m = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &temp);
		if (temp > 0)
			arr_plus[idx_p++] = temp;
		else
			arr_minus[idx_m++] = temp;
	}

	quickSort_p(0, idx_p - 1);
	quickSort_m(0, idx_m - 1);

	int total = 0;
	int i = 0;
	if (idx_p == 1)
	{
		total += arr_plus[0];
	}
	else
	{
		for (; i < idx_p; i += 2)
		{
			int num1 = arr_plus[i];
			if (num1 == 1 || num1 == 0)
				break;
			int num2 = arr_plus[i + 1];
			if (num2 == 1 || num2 == 0)
				break;

			total += (num1 * num2);
		}
		for (; i < idx_p; ++i)
			total += arr_plus[i];
	}

	i = 0;
	if (idx_m == 1)
	{
		total += arr_minus[0];
	}
	else
	{
		for (; i < idx_m; i += 2)
		{
			int num1 = arr_minus[i];
			if (i + 1 == idx_m)break;
			int num2 = arr_minus[i + 1];
			total += (num1 * num2);
		}
		for (; i < idx_m; ++i)
			total += arr_minus[i];
	}
	printf("%d\n", total);
}