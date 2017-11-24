#pragma warning(disable : 4996)
#include<cstdio>
#include<map>
using namespace std;

map<int, int> ma;
int arr[10][10];
int T;
int check();
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		for (int i = 1; i <= 9; ++i)
		{
			for (int j = 1; j <= 9; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		ma.clear();
		if (check())
			printf("#%d 1\n", tc + 1);
		else
			printf("#%d 0\n", tc + 1);
	}
}
int check()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			if (!ma.count(arr[i][j]))
				ma[arr[i][j]] = 1;
			else
				return 0;
		}
		ma.clear();
	}

	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			if (!ma.count(arr[j][i]))
				ma[arr[j][i]] = 1;
			else
				return 0;
		}
		ma.clear();
	}


	for (int k = 0; k < 7; k += 3)
	{
		for (int i = 1 + k; i <= 3+k; ++i)
		{
			for (int j = 1 + k; j <= 3+k; ++j)
			{
				if (!ma.count(arr[i][j]))
					ma[arr[i][j]] = 1;
				else
					return 0;
			}
		}
		ma.clear();
	}
	return 1;
}