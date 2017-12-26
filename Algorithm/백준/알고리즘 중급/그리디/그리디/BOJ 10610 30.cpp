#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

char str[7];
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
			while (str[i] >= str[pivot] && i < last)
			{
				i++;
			}
			while (str[j] < str[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}

		temp = str[pivot];
		str[pivot] = str[j];
		str[j] = temp;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}

int main()
{
	scanf("%s", str);
	int sum = 0;
	int i = 0;
	for (; str[i] != '\0'; ++i)
		sum += str[i] - '0';


	quickSort(0, i);
	if (sum % 3) { printf("-1\n"); return 0; }
	else
		if (str[--i] != '0') { printf("-1\n"); return 0; }

	for (i = 0; str[i] != '\0'; ++i)
		printf("%c", str[i]);
	printf("\n");
}