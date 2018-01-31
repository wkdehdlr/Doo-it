#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>
#include<stdio.h>
using namespace std;

char str[29];
int arr[9][9];
bool check[3][9][10];
int N;

void print()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}
bool func(int row, int col)
{
	if (row == 8 && col == 8)
	{
		if (arr[row][col])
		{
			print();
			return true;
		}
		for (int i = 1; i <= 9; ++i)
		{
			if (!check[0][row][i] && !check[1][col][i] && !check[2][(row / 3) * 3 + col / 3][i])
			{
				arr[row][col] = i;
				print();
				return true;
			}
		}
	}
	else if (arr[row][col])
	{
		return func(col + 1 == 9 ? row + 1 : row, (col + 1) % 9);
	}
	else
	{
		for (int i = 1; i <= 9; ++i)
		{
			if (!check[0][row][i] && !check[1][col][i] && !check[2][(row / 3) * 3 + col / 3][i])
			{
				arr[row][col] = i;
				check[0][row][i] = true;
				check[1][col][i] = true;
				check[2][(row / 3) * 3 + col / 3][i] = true;
			
				if (func(col + 1 == 9 ? row + 1 : row, (col + 1) % 9))
					return true;

				arr[row][col] = 0;
				check[0][row][i] = false;
				check[1][col][i] = false;
				check[2][(row / 3) * 3 + col / 3][i] = false;
			}
		}
		return false;
	}
}
int main()
{
	for (int tc=1; scanf("%d", &N), N != 0;tc++)
	{
		memset(check, false, sizeof(check));
		memset(arr, 0, sizeof(arr));

		fgets(str, 2, stdin);
		for (int i = 0; i < N; ++i)
		{
			fgets(str, 11, stdin);
			int row, col, data;
			row = str[2] - 'A';
			col = str[3] - '0' - 1;
			data = str[0] - '0';

			arr[row][col] = data;
			check[0][row][data] = true;
			check[1][col][data] = true;
			check[2][(row / 3) * 3 + col / 3][data] = true;


			row = str[7] - 'A';
			col = str[8] - '0' - 1;
			data = str[5] - '0';

			arr[row][col] = data;
			check[0][row][data] = true;
			check[1][col][data] = true;
			check[2][(row / 3) * 3 + col / 3][data] = true;
			
		}
		fgets(str, sizeof(str), stdin);
		for (int i = 0; i < 9; ++i)
		{
			int row, col, data;
			row = str[3 * i] - 'A';
			col = str[3 * i + 1] - '0' - 1;
			data = i + 1;

			arr[row][col] = data;
			check[0][row][data] = true;
			check[1][col][data] = true;
			check[2][(row / 3) * 3 + col / 3][data] = true;
		}
		printf("Puzzle %d\n", tc);
		func(0, 0);
	}
}
/*

83
61
64
75
39
19
84
27
63
51
42
92
74
39
68
97
54
18
32
48
25
76
91

*/