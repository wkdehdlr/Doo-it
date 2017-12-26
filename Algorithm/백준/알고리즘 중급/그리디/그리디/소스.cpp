#pragma warning(disable : 4996)
#include<cstdio>
int input[5] = { 1,2,3,4,5 };
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
			while (input[i] >= input[pivot] && i < last)
			{
				i++;
			}
			while (input[j] < input[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}

		temp = input[pivot];
		input[pivot] = input[j];
		input[j] = temp;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}
int main()
{
	quickSort(0, 4);
	return 0;
}