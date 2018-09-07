#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
struct dat {
	int x, y;
}data[1000];
int arr[35][25];
int arr2[35][25];
int chk[1000];
int ary[3];
int N, M, H;
int idx = 1;
void init()
{
	scanf("%d %d %d", &N, &M, &H);
	for (int j = 1; j <= N; ++j) {
		for (int i = 0; i <= H + 1; ++i) {
			arr[i][2 * j - 1] = 1;
		}
	}
	for (int k = 0; k < M; ++k) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][2 * b] = 1;
	}
	for (int i = 1; i <= H; ++i) {
		for (int j = 2; j < 2 * N - 1; j += 2) {
			if (arr[i][j] == 0 && arr[i][j - 2] == 0 && arr[i][j + 2] == 0) {
				data[idx].x = i; data[idx].y = j;
				idx++;
			}
		}
	}
	idx -= 1;
}
int check(int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)continue;
			if (data[ary[i]].x == data[ary[j]].x &&
				abs(data[ary[i]].y - data[ary[j]].y) == 2)return 1;
		}
	}
	return 0;
}
int go(int i, int j)
{
	if (i == H + 1)return j;
	if (arr2[i][j - 1] == 1)return go(i + 1, j - 2);
	if (arr2[i][j + 1] == 1)return go(i + 1, j + 2);
	return go(i + 1, j);
}
int start(int n)
{
	for (int i = 0; i < 35; ++i)for (int j = 0; j < 25; ++j)arr2[i][j] = arr[i][j];
	for (int i = 0; i < n; ++i) {
		arr2[data[ary[i]].x][data[ary[i]].y] = 1;
	}

	for (int j = 1; j <= 2 * N - 1; j += 2)
		if (j != go(0, j))return 0;
	return 1;
}
int dfs(int ix ,int n, int k)
{
	if (!k) {
		if (check(n))return 0;
		if (start(n))return 1;
		return 0;
	}
	for (int i = ix; i <= idx; ++i) {
		if (chk[i])continue;
		chk[i] = 1;
		ary[n] = i;
		if (dfs(i + 1, n + 1, k - 1))return 1;
		chk[i] = 0;
	}
	return 0;
}
int main()
{
	init();
	bool ok = true;
	for (int k = 0; k < 4; ++k) {
		if (dfs(1, 0, k)) {
			printf("%d\n", k);
			ok = false;
			break;
		}
	}
	if (ok)printf("-1\n");
	return 0;
}