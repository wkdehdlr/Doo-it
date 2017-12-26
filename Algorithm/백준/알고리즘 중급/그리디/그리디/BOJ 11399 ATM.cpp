#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int input[1000];
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
			while (input[i] <= input[pivot] && i < last)
			{
				i++;
			}
			while (input[j] > input[pivot])
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
	int cnt = 0, total = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)	scanf("%d", &input[i]);
	quickSort(0, N - 1);
	for (int i = 0; i < N; ++i) { cnt += input[i]; total += cnt; }		
	printf("%d\n", total);
}