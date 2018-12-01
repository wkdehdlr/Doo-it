#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
struct node {
	int x, y;
};
queue<node> q;
queue<node> q2;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int visited[55][55];
int visited2[55][55];
int arr[55][55];
int N, L, R, cnt = 0;
int tot = 0;
void input()
{
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
}
void BFS()
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 0 && r < N && c >= 0 && c < N && !visited[r][c]) {
				int num = abs(arr[r][c] - arr[x][y]);
				if (num >= L && num <= R) {
					visited[r][c] = visited[x][y];
					q.push({ r,c });
				}
			}
		}
	}
}
int BFSS()
{
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		tot += arr[x][y];
		for (int k = 0; k < 4; ++k) {
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 0 && r < N && c >= 0 && c < N && !visited2[r][c] && visited[x][y] == visited[r][c]) {
				visited2[r][c] = 1;
				q.push({ r,c });
				q2.push({ r,c });
			}
		}
	}

	int sz = q2.size();
	if (sz == 1) {
		q2.pop();
		return 0;
	}
	tot /= sz;
	while (!q2.empty()) {
		int x = q2.front().x;
		int y = q2.front().y;
		q2.pop();
		arr[x][y] = tot;
	}
	return 1;
}
int func()
{
	bool ok = false;
	int k = 1;
	memset(visited, 0, sizeof(visited));
	memset(visited2, 0, sizeof(visited2));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j]) {
				visited[i][j] = k++;
				q.push({ i,j });
				BFS();
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited2[i][j]) {
				visited2[i][j] = 1;
				q.push({ i,j });
				q2.push({ i,j });
				tot = 0;
				if (BFSS()) {
					ok = true;
				}
			}
		}
	}
	return ok;
}
int main()
{
	input();
	while (func())cnt++;
	printf("%d\n", cnt);
}