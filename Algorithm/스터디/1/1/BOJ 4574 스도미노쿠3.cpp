#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>
using namespace std;

int dr[2] = { 0,1 };
int dc[2] = { 1,0 };


int arr[9][9];
bool check[3][9][10];
bool domino[10][10];
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
void func_on(int row, int col, int num1, int x, int y, int num2)
{
	arr[row][col] = num1;
	check[0][row][num1] = true;
	check[1][col][num1] = true;
	check[2][(row / 3) * 3 + col / 3][num1] = true;
	arr[x][y] = num2;
	check[0][x][num2] = true;
	check[1][y][num2] = true;
	check[2][(x / 3) * 3 + y / 3][num2] = true;
	num1 > num2 ? domino[num2][num1] = true : domino[num1][num2] = true;
}
void func_off(int row, int col, int num1, int x, int y, int num2)
{
	arr[row][col] = 0;
	check[0][row][num1] = false;
	check[1][col][num1] = false;
	check[2][(row / 3) * 3 + col / 3][num1] = false;
	arr[x][y] = 0;
	check[0][x][num2] = false;
	check[1][y][num2] = false;
	check[2][(x / 3) * 3 + y / 3][num2] = false;
	num1 > num2 ? domino[num2][num1] = false : domino[num1][num2] = false;
}
bool func(int row, int col)
{
	if (row == 8 && col == 8)
	{
		print();
		return true;
	}
	else if (arr[row][col])
	{
		return func(col + 1 == 9 ? row + 1 : row, (col + 1) % 9);
	}
	else
	{
		for (int i = 0; i < 2; ++i)
		{
			int x = row + dr[i];
			int y = col + dc[i];
			if (x < 9 && y < 9 && !arr[x][y])
			{
				for (int num1 = 1; num1 < 10; num1++)
				{
					for (int num2 = num1 + 1; num2 < 10; num2++)
					{
						if (!domino[num1][num2])
						{
							if (!check[0][row][num1] && !check[1][col][num1] && !check[2][(row / 3) * 3 + col / 3][num1] &&
								!check[0][x][num2] && !check[1][y][num2] && !check[2][(x / 3) * 3 + y / 3][num2])
							{
								func_on(row, col, num1, x, y, num2);
								if (func(col + 1 == 9 ? row + 1 : row, (col + 1) % 9))
									return true;
								func_off(row, col, num1, x, y, num2);
							}

							if (!check[0][row][num2] && !check[1][col][num2] && !check[2][(row / 3) * 3 + col / 3][num2] &&
								!check[0][x][num1] && !check[1][y][num1] && !check[2][(x / 3) * 3 + y / 3][num1])
							{
								func_on(row, col, num2, x, y, num1);
								if (func(col + 1 == 9 ? row + 1 : row, (col + 1) % 9))
									return true;
								func_off(row, col, num2, x, y, num1);
							}
						}
					}
				}
			}
		}
		return false;
	}
}
int main()
{
	for (int tc = 1; scanf("%d", &N), N != 0; tc++)
	{
		memset(check, false, sizeof(check));
		memset(arr, 0, sizeof(arr));
		memset(domino, false, sizeof(domino));
		int num1,num2;
		char str1[3],str2[3];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %s %d %s", &num1, str1, &num2, str2);
			int row, col, data, data2;
			row = str1[0] - 'A';
			col = str1[1] - '1';
			data = num1;

			arr[row][col] = data;
			check[0][row][data] = true;
			check[1][col][data] = true;
			check[2][(row / 3) * 3 + col / 3][data] = true;


			row = str2[0] - 'A';
			col = str2[1] - '1';
			data2 = num2;

			arr[row][col] = data2;
			check[0][row][data2] = true;
			check[1][col][data2] = true;
			check[2][(row / 3) * 3 + col / 3][data2] = true;

			data > data2 ? domino[data2][data] = true : domino[data][data2] = true;
		}
		for (int i = 0; i < 9; ++i)
		{
			scanf("%s", str1);
			int row, col, data;
			row = str1[0] - 'A';
			col = str1[1] - '1';
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