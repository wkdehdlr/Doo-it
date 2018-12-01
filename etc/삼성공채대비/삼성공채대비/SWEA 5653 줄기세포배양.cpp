#pragma warning(disable : 4996)
#define DEAD 0
#define ON 1
#define OFF 2
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
struct node {
	int x, y, k, now, state;
};
queue<node> q;
queue<node> q2;
int visited[500][500];
int arr2[500][500];
int T, N, M, K;
void input()
{
	while (!q.empty())q.pop();
	memset(visited, 0, sizeof(visited));
	int k;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &k);
			if (!k)continue;
			q.push({ i + 200,j + 200,k,k,OFF });
			visited[i + 200][j + 200] = 1;
		}
	}
}
void func()
{
	int sz = q.size();
	while (sz--) {
		node n = q.front();
		q.pop();

		if (n.state == OFF) {
			n.now--;
			if (n.now == 0) {
				n.now = n.k;
				n.state = ON;
			}
			q.push(n);
		}
		else if (n.state == ON) {
			for (int k = 0; k < 4; ++k) {
				int r = n.x + dr[k];
				int c = n.y + dc[k];
				if (!visited[r][c]) {
					q2.push({ r,c,n.k,0,0 });
				}
			}
			n.now--;
			if (n.now != 0)q.push(n);
		}
	}
	sz = q2.size();
	while (sz--) {
		node n = q2.front();
		q2.pop();
		if (arr2[n.x][n.y] < n.k)arr2[n.x][n.y] = n.k;
		q2.push(n);
	}

	while (!q2.empty()) {
		node n = q2.front();
		q2.pop();
		if (arr2[n.x][n.y]) {
			q.push({ n.x,n.y,arr2[n.x][n.y],arr2[n.x][n.y],OFF });
			arr2[n.x][n.y] = 0;
			visited[n.x][n.y] = 1;
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		input();
		while (K--)func();
		printf("#%d %d\n", tc + 1, q.size());
	}
}