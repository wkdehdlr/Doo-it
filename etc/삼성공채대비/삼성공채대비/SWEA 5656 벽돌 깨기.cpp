#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
struct node {
	int x, y, cnt;
};
queue<node> q;
int T, N, W, H, mn;
int count(int arr[][16])
{
	int cnt = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (arr[i][j])cnt++;
		}
	}
	return cnt;
}
void destroy(int y, int tmp[][16])
{
	for (int i = 0; i < H; ++i) {
		if (tmp[i][y]) {
			q.push({ i,y,tmp[i][y] });
			tmp[i][y] = 0;
			break;
		}
	}
	while (!q.empty()) {
		node n = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int r = n.x;
			int c = n.y;
			for (int i = 1; i < n.cnt; ++i) {
				r += dr[k];
				c += dc[k];
				if (r >= 0 && r < H && c >= 0 && c < W && tmp[r][c]) {
					q.push({ r,c,tmp[r][c] });
					tmp[r][c] = 0;
				}
			}
		}
	}
	for (int y = 0; y < W; ++y) {
		for (int x = H - 1; x >= 0; --x) {
			if (!tmp[x][y]) {
				int r = x - 1, c = y;
				while (r >= 0 && !tmp[r][c])--r;
				if (r < 0)break;
				tmp[x][y] = tmp[r][c];
				tmp[r][c] = 0;
			}
		}
	}
}
void DFS(int n, int arr[][16])
{
	if (n == N) {
		mn = min(mn, count(arr));
	}
	else {
		int tmp[16][16];
		memcpy(tmp, arr, sizeof(tmp));
		for (int i = 0; i < W; ++i) {
			destroy(i, tmp);
			DFS(n + 1,tmp);
			memcpy(tmp, arr, sizeof(tmp));
		}
	}
}
void input(int arr[][16])
{
	mn = 999999999;
	scanf("%d %d %d", &N, &W, &H);
	for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) scanf("%d", &arr[i][j]);	
}
int main()
{
	int arr[16][16];
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		input(arr);
		DFS(0, arr);
		printf("#%d %d\n", tc + 1, mn);
	}
}