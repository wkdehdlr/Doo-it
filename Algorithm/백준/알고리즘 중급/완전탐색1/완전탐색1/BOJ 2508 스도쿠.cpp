#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int arr[9][9];
bool arr_garo[9][10];
bool arr_sero[9][10];
bool arr_nemo[3][3][10];

bool check(int x,int y,int num)
{
	if (!arr_garo[x][num] && !arr_sero[y][num] && !arr_nemo[x / 3][y / 3][num])
		return true;
	else
		return false;
}

bool func(int x, int y)
{
	if (x == 9)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				printf("%d ", arr[i][j]);
			printf("\n");
		}

		return true;
	}
	else
	{
		if (!arr[x][y])
		{
			for (int i = 1; i <= 9; ++i)
			{
				if (check(x, y, i))
				{
					bool res = false;
					arr[x][y] = i;
					arr_garo[x][i] = true;
					arr_sero[y][i] = true;
					arr_nemo[x / 3][y / 3][i] = true;
					y == 8 ? res = func(x + 1, (y + 1) % 9) : res = func(x, (y + 1) % 9);
					if (res)return true;
					arr[x][y] = 0;
					arr_garo[x][i] = false;
					arr_sero[y][i] = false;
					arr_nemo[x / 3][y / 3][i] = false;
				}
			}
			return false;
		}
		else
		{
			bool res = false;
			y == 8 ? res = func(x + 1, (y + 1) % 9) : res = func(x, (y + 1) % 9);
			if (res)return true; else return false;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			scanf("%d", &arr[i][j]);
			arr_garo[i][arr[i][j]] = true;
			arr_sero[j][arr[i][j]] = true;
			arr_nemo[i / 3][j / 3][arr[i][j]] = true;
		}
	}
	func(0, 0);
}