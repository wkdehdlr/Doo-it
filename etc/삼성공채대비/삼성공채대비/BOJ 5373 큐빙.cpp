#pragma warning(disable : 4996)
#include<cstdio>
#define WHITE 1
#define GREEN 2
#define RED 3
#define ORAGNE 4
#define BLUE 5
#define YELLOW 6

int tmp[4];
int cube[8][4][4];
int arr[7] = { 0,WHITE,GREEN,RED,ORAGNE,BLUE,YELLOW };

int T, N;
char rot[3];
void init()
{
	for (int i = 1; i <= 6; ++i) {
		for (int r = 1; r <= 3; ++r) {
			for (int c = 1; c <= 3; ++c) {
				cube[i][r][c] = arr[i];
			}
		}
	}
}
void my(int k, bool ok)
{
	if (ok) {//오른쪽
		for (int j = 1; j <= 3; ++j) {
			for (int i = 3; i >= 1; --i) {
				cube[7][j][4 - i] = cube[k][i][j];
			}
		}
	}
	else {//왼쪽
		for (int j = 3; j >= 1; --j) {
			for (int i = 1; i <= 3; ++i) {
				cube[7][4 - j][i] = cube[k][i][j];
			}
		}
	}
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cube[k][i][j] = cube[7][i][j];
		}
	}
}
void around(int k, bool ok)
{
	if (k == 1) {
		//뒤4 오5 앞3 왼2
		if (ok) {//오른쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[4][1][i];
			for (int i = 1; i <= 3; ++i)cube[4][1][i] = cube[2][1][i];
			for (int i = 1; i <= 3; ++i)cube[2][1][i] = cube[3][1][i];
			for (int i = 1; i <= 3; ++i)cube[3][1][i] = cube[5][1][i];
			for (int i = 1; i <= 3; ++i)cube[5][1][i] = tmp[i];
		}
		else {//왼쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[4][1][i];
			for (int i = 1; i <= 3; ++i)cube[4][1][i] = cube[5][1][i];
			for (int i = 1; i <= 3; ++i)cube[5][1][i] = cube[3][1][i];
			for (int i = 1; i <= 3; ++i)cube[3][1][i] = cube[2][1][i];
			for (int i = 1; i <= 3; ++i)cube[2][1][i] = tmp[i];
		}
	}
	else if (k == 2) {
		//위1 앞3 아6 뒤4
		//
		if (ok) {//오른쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[1][i][1];
			for (int i = 1; i <= 3; ++i)cube[1][i][1] = cube[4][4 - i][3];
			for (int i = 1; i <= 3; ++i)cube[4][i][3] = cube[6][4 - i][1];
			for (int i = 1; i <= 3; ++i)cube[6][i][1] = cube[3][i][1];
			for (int i = 1; i <= 3; ++i)cube[3][i][1] = tmp[i];
		}
		else {//왼쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[1][i][1];
			for (int i = 1; i <= 3; ++i)cube[1][i][1] = cube[3][i][1];
			for (int i = 1; i <= 3; ++i)cube[3][i][1] = cube[6][i][1];
			for (int i = 1; i <= 3; ++i)cube[6][i][1] = cube[4][4 - i][3];
			for (int i = 1; i <= 3; ++i)cube[4][4 - i][3] = tmp[i];
		}
	}
	else if (k == 3) {
		//위1 오5 아6 왼2
		if (ok) {//오른쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[1][3][i];
			for (int i = 1; i <= 3; ++i)cube[1][3][i] = cube[2][4-i][3];
			for (int i = 1; i <= 3; ++i)cube[2][i][3] = cube[6][1][i];
			for (int i = 1; i <= 3; ++i)cube[6][1][i] = cube[5][4-i][1];
			for (int i = 1; i <= 3; ++i)cube[5][i][1] = tmp[i];
		}
		else {//왼쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[1][3][i];
			for (int i = 1; i <= 3; ++i)cube[1][3][i] = cube[5][i][1];
			for (int i = 1; i <= 3; ++i)cube[5][i][1] = cube[6][1][4-i];
			for (int i = 1; i <= 3; ++i)cube[6][1][i] = cube[2][i][3];
			for (int i = 1; i <= 3; ++i)cube[2][i][3] = tmp[4-i];
		}
	}
	else if (k == 4) {
		//위1 왼2 아6 오5
		if (ok) {//오른쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[1][1][i];
			for (int i = 1; i <= 3; ++i)cube[1][1][i] = cube[5][i][3];
			for (int i = 1; i <= 3; ++i)cube[5][i][3] = cube[6][3][4-i];
			for (int i = 1; i <= 3; ++i)cube[6][3][i] = cube[2][i][1];
			for (int i = 1; i <= 3; ++i)cube[2][i][1] = tmp[4-i];
		}
		else {//왼쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[1][1][i];
			for (int i = 1; i <= 3; ++i)cube[1][1][i] = cube[2][4-i][1];
			for (int i = 1; i <= 3; ++i)cube[2][i][1] = cube[6][3][i];
			for (int i = 1; i <= 3; ++i)cube[6][3][i] = cube[5][4-i][3];
			for (int i = 1; i <= 3; ++i)cube[5][i][3] = tmp[i];
		}
	}
	else if (k == 5) {
		//위1 뒤4 아래6 앞3
		if (ok) {//오른쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[1][i][3];
			for (int i = 1; i <= 3; ++i)cube[1][i][3] = cube[3][i][3];
			for (int i = 1; i <= 3; ++i)cube[3][i][3] = cube[6][i][3];
			for (int i = 1; i <= 3; ++i)cube[6][i][3] = cube[4][4-i][1];
			for (int i = 1; i <= 3; ++i)cube[4][i][1] = tmp[4-i];
		}
		else {//왼쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[1][i][3];
			for (int i = 1; i <= 3; ++i)cube[1][i][3] = cube[4][4-i][1];
			for (int i = 1; i <= 3; ++i)cube[4][i][1] = cube[6][4-i][3];
			for (int i = 1; i <= 3; ++i)cube[6][i][3] = cube[3][i][3];
			for (int i = 1; i <= 3; ++i)cube[3][i][3] = tmp[i];
		}
	}
	else {
		//앞3 오5 뒤4 왼2
		if (ok) {//오른쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[3][3][i];
			for (int i = 1; i <= 3; ++i)cube[3][3][i] = cube[2][3][i];
			for (int i = 1; i <= 3; ++i)cube[2][3][i] = cube[4][3][i];
			for (int i = 1; i <= 3; ++i)cube[4][3][i] = cube[5][3][i];
			for (int i = 1; i <= 3; ++i)cube[5][3][i] = tmp[i];
		}
		else {//왼쪽
			for (int i = 1; i <= 3; ++i)tmp[i] = cube[3][3][i];
			for (int i = 1; i <= 3; ++i)cube[3][3][i] = cube[5][3][i];
			for (int i = 1; i <= 3; ++i)cube[5][3][i] = cube[4][3][i];
			for (int i = 1; i <= 3; ++i)cube[4][3][i] = cube[2][3][i];
			for (int i = 1; i <= 3; ++i)cube[2][3][i] = tmp[i];
		}
	}
}
void func()
{
	bool ok = rot[1] == '+' ? true : false;
	switch (rot[0])
	{
	case 'U':my(1, ok); around(1, ok); break;
	case 'D':my(6, ok); around(6, ok); break;
	case 'F':my(3, ok); around(3, ok); break;
	case 'B':my(4, ok); around(4, ok); break;
	case 'L':my(2, ok); around(2, ok); break;
	case 'R':my(5, ok); around(5, ok); break;
	}
}
void output()
{
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			char ch;
			if (cube[1][i][j] == WHITE)ch = 'w';
			else if (cube[1][i][j] == GREEN)ch = 'g';
			else if (cube[1][i][j] == RED)ch = 'r';
			else if (cube[1][i][j] == ORAGNE)ch = 'o';
			else if (cube[1][i][j] == BLUE)ch = 'b';
			else if (cube[1][i][j] == YELLOW)ch = 'y';
			printf("%c", ch);
		}
		printf("\n");
	}
}
int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		init();
		for (int j = 0; j < N; ++j) {
			scanf("%s", rot);
			func();
		}
		output();
	}
}