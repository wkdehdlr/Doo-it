#pragma warning(disable : 4996)
#include<cstdio>
int arr[6] = {1,2,3,0,4,5 };
int cnt[11];
int sortedArr[6];
int N = 6;
void calculateDigitNumber()
{
	for (int i = 0; i < N; i++)
	{
		cnt[arr[i]]++;
	}

	for (int i = 0; i < 10; i++)
	{
		cnt[i] = cnt[i - 1] + cnt[i];
	}
}

void executeCountingSort()
{
	for (int i = 0; i < N; i++)
	{
		sortedArr[--cnt[arr[i]]] = arr[i];
	}
}
int main()
{
	calculateDigitNumber();
	executeCountingSort();

	//print the sorted digits
	for (int i = N-1; i >= 0; i--)
	{
		printf("%d ", sortedArr[i]);
	}
	//quickSort(0, 4);
	return 0;
}