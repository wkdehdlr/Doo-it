#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

char new_arr[5];
char arr[5];
int L, C;

void func(int n,int l)
{
	if (l == L)
	{
		printf("%s\n", new_arr);
	}
	else
	{
		for (int i = n; i < C; ++i)
		{
			new_arr[n] = arr[i];
			func(n+1, l + 1);
			new_arr[n] = '\0';
		}
	}
}

int main()
{
	char tmp;
	scanf("%d %d%c", &L, &C, &tmp);
	for (int i = 0; i < C; ++i)
	{
		scanf("%c%c", &arr[i], &tmp);
	}
	sort(arr, arr + C);
	func(0,0);
}