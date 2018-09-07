#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

struct puzzle {
	int arr[4];
	int same = 0;
}puz[2510];
int ary[55][55];
int chk[2510];
int N, M, NN, T;
char str[20];
void encode(int i, int j)
{
	int s = 1;
	int tmp = 0;
	for (int k = 1; k < M - 1; ++k) {
		s *= 3;
		tmp *= 3;
		if (str[k] == '0')tmp += 1;
		else if (str[k] == 'M')tmp += 0;
		else if (str[k] == 'F')tmp += 2;
	}
	if (j < 2)puz[i].arr[j] = tmp;
	else puz[i].arr[j] = s - tmp - 1;
}
void input()
{
	scanf("%d %d %d", &N, &M, &T);
	NN = N * N + T;
	for (int i = 0; i < NN; ++i) {
		for (int j = 0; j < 4; ++j) {
			scanf("%s", str);
			encode(i, j);
		}
	}
}
void setting()
{
	for (int i = 0; i < NN; ++i) {
		for (int j = 0; j < NN; ++j) {
			if (puz[i].arr[3] == puz[j].arr[1])puz[i].same++;
			if (puz[i].arr[2] == puz[j].arr[0])puz[i].same++;
		}
	}
}
int dfs(int n)
{
	if (n == NN - T)return 1;
	int r = n / N;
	int c = n % N;
	for (int i = 0; i < NN; i++) {
		if (chk[i])continue;
		if (c != 0) {
			if (puz[ary[r][c - 1]].arr[0] == puz[i].arr[2]) {
				ary[r][c] = i;
				chk[i] = 1;
				if (dfs(n + 1))return 1;
				chk[i] = 0;
			}
		}
		else {
			if (puz[ary[r - 1][c]].arr[1] == puz[i].arr[3]) {
				ary[r][c] = i;
				chk[i] = 1;
				if (dfs(n + 1))return 1;
				chk[i] = 0;
			}
		}
	}
	return 0;
}
int process(int same_cnt)
{
	for (int i = 0; i < NN; ++i) {
		if (puz[i].same == same_cnt) {
			ary[0][0] = i;
			chk[i] = 1;
			if (dfs(1))return 1;
			chk[i] = 0;
		}
	}
	return 0;
}
int main()
{
	input();
	setting();
	for (int i = 0; i <= T; ++i)
		if (process(i))break;
	int r, c;
	scanf("%d %d", &r, &c);
	printf("%d\n", ary[r][c]);
	for (int i = 0; i < NN; ++i)
		if (!chk[i])printf("%d ", i);
	printf("\n");
}