#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

char str[100001];
#define MAX_DIGIT 10

int cnt[MAX_DIGIT];
int sortedArr[100001];
void calculateDigitNumber(int num)
{
	for (int i = 0; i < num; i++)
	{
		cnt[str[i]-'0']++;
	}

	for (int i = 0; i < MAX_DIGIT; i++)
	{
		cnt[i] = cnt[i - 1] + cnt[i];
	}
}

void executeCountingSort(int num)
{
	for (int i = num - 1; i >= 0; i--)
	{
		sortedArr[--cnt[str[i]-'0']] = str[i]-'0';
	}
}
void insertionSort(int num)
{
	char temp;
	int i;
	int j;

	for (i = 1; i < num; i++)
	{
		temp = str[i];
		j = i - 1;

		while ((temp > str[j]) && (j >= 0))
		{
			str[j + 1] = str[j];
			j = j - 1;
		}
		str[j + 1] = temp;
	}
}
int main()
{
	scanf("%s", str);
	int sum = 0;
	int i = 0;
	for (; str[i] != '\0'; ++i)
		sum += str[i] - '0';

	calculateDigitNumber(i);
	executeCountingSort(i);
	//insertionSort(i);
	//sort(str, str + i,greater<int>());
	//quickSort(0, i-1);
	//i = 0;
	if (sum % 3) { printf("-1\n"); return 0; }
	else
		if (sortedArr[0] != 0) { printf("-1\n"); return 0; }

	for (--i; i>=0; --i)
		printf("%d", sortedArr[i]);
	printf("\n");
}