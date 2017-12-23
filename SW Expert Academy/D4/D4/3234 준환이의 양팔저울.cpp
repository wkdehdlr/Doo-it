#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

#define MAX_STRING_LENGTH 10

char combinationStack[MAX_STRING_LENGTH];
int N, T; 
void swap(int *x, int *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permutation(int *str, int l, int r)
{
	if (l == r)
	{
		for (int i = 0; i < N; ++i)
		{
			printf("%d", str[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap((str + l), (str + i));
			permutation(str, l + 1, r);
			swap((str + l), (str + i)); //backtrack
		}
	}
}


int main()
{
	
	int str[MAX_STRING_LENGTH];
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &str[i]);
		}
		printf("#%d\n", test_case);
		permutation(str, 0, N - 1);
	}
	return 0;
}