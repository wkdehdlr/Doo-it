#pragma warning(disable : 4996)
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

struct node {
	int x, y, dir, cnt;
};
queue<node> q;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int arr[55][55];
//int visited[55][55];
int T, N, ret;
void input()
{
	//memset(visited, 0, sizeof(visited));
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)for (int j = 0; j < N; ++j)scanf("%d", &arr[i][j]);
	while (!q.empty())q.pop();
}
int func2(node n)
{
	int r = n.x;
	int c = n.y;
	if (arr[n.x][n.y] == 0)return 0;
	else if (arr[n.x][n.y] == 1 || arr[n.x][n.y] == 2) {// คั  |
		if (n.dir == LEFT)c += dc[2];
		else if (n.dir == RIGHT)c += dc[0];
		else if (n.dir == UP)r += dr[1];
		else if (n.dir == DOWN)r += dr[3];

		if (r == N - 1 && c == N)return n.cnt;
		if (r >= 0 && r < N && c >= 0 && c < N) {
			//visited[r][c] = visited[n.x][n.y] + 1;
			q.push({ r,c,n.dir,n.cnt + 1 });
		}
	}
	else{
		if (n.dir == LEFT || n.dir == RIGHT) {
			r = n.x + dr[3];
			c = n.y + dc[3];
			if (r == N - 1 && c == N)return n.cnt;
			if (r >= 0 && r < N && c >= 0 && c < N) {
				//visited[r][c] = visited[n.x][n.y] + 1;
				q.push({ r,c,DOWN,n.cnt + 1 });
			}
			r = n.x + dr[1];
			c = n.y + dc[1];
			if (r == N - 1 && c == N)return n.cnt;
			if (r >= 0 && r < N && c >= 0 && c < N) {
				//visited[r][c] = visited[n.x][n.y] + 1;
				q.push({ r,c,UP,n.cnt + 1 });
			}
		}
		else if (n.dir == UP || n.dir == DOWN) {
			r = n.x + dr[0];
			c = n.y + dc[0];
			if (r == N - 1 && c == N)return n.cnt;
			if (r >= 0 && r < N && c >= 0 && c < N) {
				//visited[r][c] = visited[n.x][n.y] + 1;
				q.push({ r,c,RIGHT,n.cnt + 1 });
			}
			r = n.x + dr[2];
			c = n.y + dc[2];
			if (r == N - 1 && c == N)return n.cnt;
			if (r >= 0 && r < N && c >= 0 && c < N) {
				//visited[r][c] = visited[n.x][n.y] + 1;
				q.push({ r,c,LEFT,n.cnt + 1 });
			}
		}
	}
	return 0;
}
void func()
{
	q.push({ 0,0,LEFT,1 });
	//visited[0][0] = 1;
	while (!q.empty()) {
		node n = q.front();
		q.pop();
		ret = func2(n);
		if (ret) {
			printf("%d\n", ret);
			return;
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		printf("#%d ", tc + 1);
		input();
		func();
	}
}