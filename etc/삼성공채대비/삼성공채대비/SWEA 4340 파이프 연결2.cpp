#pragma warning(disable : 4996)
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#include<stdio.h>

int mn;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int arr[55][55];
int visited[55][55];
int T, N, ret;
int min(int a, int b) {
	return a > b ? b : a;
}
void input()
{
	mn = 123456789;
	for (int i = 0; i < 55; ++i)for (int j = 0; j < 55; ++j)visited[i][j] = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)for (int j = 0; j < N; ++j)scanf("%d", &arr[i][j]);
}
void DFS(int x, int y, int dir, int cnt)
{
	int r = x, c = y;
	if (arr[x][y] == 1 || arr[x][y] == 2) {// คั |
		if (dir == LEFT)c += dc[2];
		else if (dir == RIGHT)c += dc[0];
		else if (dir == UP)r += dr[1];
		else if (dir == DOWN)r += dr[3];

		if (r == N-1 && c == N) {
			mn = min(mn, cnt);
			return;
		}
		if (r >= 0 && r < N && c >= 0 && c < N && arr[r][c] && !visited[r][c] && cnt + 1 < mn) {
			visited[r][c] = 1;
			DFS(r, c, dir, cnt + 1);
			visited[r][c] = 0;
		}
	}
	else{
		if (dir == LEFT || dir == RIGHT) {
			r = x + dr[1];
			c = y + dc[1];

			if (r == N-1 && c == N) {
				mn = min(mn, cnt);
			}
			if (r >= 0 && r < N && c >= 0 && c < N && arr[r][c] && !visited[r][c] && cnt + 1 < mn) {
				visited[r][c] = 1;
				DFS(r, c, UP, cnt + 1);
				visited[r][c] = 0;
			}
			r = x + dr[3];
			c = y + dc[3];
			if (r == N-1 && c == N) {
				mn = min(mn, cnt);
			}
			if (r >= 0 && r < N && c >= 0 && c < N && arr[r][c] && !visited[r][c] && cnt + 1 < mn) {
				visited[r][c] = 1;
				DFS(r, c, DOWN, cnt + 1);
				visited[r][c] = 0;
			}
		}
		else if (dir == UP || dir == DOWN) {
			r = x + dr[2];
			c = y + dc[2];
			if (r == N-1 && c == N) {
				mn = min(mn, cnt);
			}
			if (r >= 0 && r < N && c >= 0 && c < N && arr[r][c] && !visited[r][c] && cnt + 1 < mn) {
				visited[r][c] = 1;
				DFS(r, c, LEFT, cnt + 1);
				visited[r][c] = 0;
			}
			r = x + dr[0];
			c = y + dc[0];
			if (r == N-1 && c == N) {
				mn = min(mn, cnt);
			}
			if (r >= 0 && r < N && c >= 0 && c < N && arr[r][c] &&  !visited[r][c] && cnt + 1 < mn) {
				visited[r][c] = 1;
				DFS(r, c, RIGHT, cnt + 1);
				visited[r][c] = 0;
			}
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		input();
		visited[0][0] = 1;
		DFS(0, 0, LEFT, 1);
		printf("#%d %d\n", tc + 1, mn);
	}
}