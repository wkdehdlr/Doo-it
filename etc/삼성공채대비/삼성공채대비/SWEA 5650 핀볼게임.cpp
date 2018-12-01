#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node {
	int x, y;
}hole[11];
int dr[4] = { 0,1,-1,0 };
int dc[4] = { -1,0,0,1 };
int arr[101][101];
int T, N, mx;
void input()
{
	for (int i = 6; i <= 10; ++i)hole[i].x = hole[i].y = 0;
	scanf("%d", &N);
	for (int i = 0; i<N; ++i) {
		for (int j = 0; j<N; ++j) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] >= 6) {
				hole[arr[i][j]].x += i;
				hole[arr[i][j]].y += j;
			}
		}
	}
}
int change(int block, int dir)
{
	if (block == 1) {
		if (dir == 2 || dir == 3)return 3 - dir;
		if (dir == 1)return 3;
		if (dir == 0)return 2;
	}
	else if (block == 2) {
		if (dir == 1 || dir == 3)return 3 - dir;
		if (dir == 2)return 3;
		if (dir == 0)return 1;
	}
	else if (block == 3) {
		if (dir == 1 || dir == 0)return 3 - dir;
		if (dir == 2)return 0;
		if (dir == 3)return 1;
	}
	else {
		if (dir == 2 || dir == 0)return 3 - dir;
		if (dir == 3)return 2;
		if (dir == 1)return 0;
	}
}
int go(int i, int j, int k)
{
	int cnt = 0;
	int r = i;
	int c = j;
	while (1) {
		r += dr[k];
		c += dc[k];
		//printf("%d %d\n",r,c);
		if (r >= 0 && r<N && c >= 0 && c<N && (arr[r][c] == -1 || (r == i && c == j)))return cnt;
		//종료조건
		if (r<0 || r >= N || c<0 || c >= N || arr[r][c] == 5) {//벽을 만나면 or 5번블록
			cnt++;
			k = 3 - k;
		}
		else {
			if (arr[r][c] >= 1 && arr[r][c] <= 4) {
				cnt++;
				k = change(arr[r][c], k);
			}
			else if (arr[r][c] >= 6) {//웜홀
				int x = r;
				int y = c;
				r = hole[arr[x][y]].x - r;
				c = hole[arr[x][y]].y - c;
			}
		}
	}
}
void func()
{
	mx = 0;
	for (int i = 0; i<N; ++i) {
		for (int j = 0; j<N; ++j) {
			if (!arr[i][j]) {
				for (int k = 0; k<4; ++k)mx = max(mx, go(i, j, k));
			}
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc<T; ++tc) {
		input();
		//printf("%d %d\n",hole[7].x,hole[7].y);
		func();
		printf("#%d %d\n", tc + 1, mx);
	}
}
