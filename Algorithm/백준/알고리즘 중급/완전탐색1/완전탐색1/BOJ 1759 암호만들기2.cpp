#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

char new_arr[16];
char arr[15];
int L, C;
 
void func()
{
	int maxN = 1 << C;
	for (int i = 0; i < maxN; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < C; ++j)
		{
			if (i & (1 << j))
			{
				new_arr[cnt++] = arr[j];
			}
		}
		if (cnt == L)
		{
			int moumm = 0;
			int zaumm = 0;
			for (int i = 0; i < L; ++i)
			{
				if (new_arr[i] == 'a' || new_arr[i] == 'e' || new_arr[i] == 'i' || new_arr[i] == 'u' || new_arr[i] == 'o')
					moumm++;
				else
					zaumm++;
			}
			if (moumm >= 1 && zaumm >= 2)
			{
				new_arr[L] = '\0', printf("%d %s\n", i,new_arr);
			}
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
	func();
}