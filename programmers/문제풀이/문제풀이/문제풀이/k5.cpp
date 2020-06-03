#pragma warning(disable : 4996)
#include<cstdio>
#include<string>
#include<vector>

#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;

bool visited[30][30];

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

vector<vector<int>> board= 0, 0, 0], [0, 0, 0], [0, 0, 0]];

int rlen = board.size();
int clen = board[0].size();
int mn = 2100000000;

void DFS(int r, int c, int d, int p) {
	if (r == rlen && c == clen) {
		mn = min(mn, p);
		return;
	}

	for (int k = 0; k < 4; ++k) {
		int nr = r + dr[k];
		int nc = c + dc[k];

		if (nr >= 0 && nr < rlen && nc >= 0 && nc < clen && !board[nr][nc] && !visited[nr][nc]) {
			visited[nr][nc] = true;
			if (d == k) {
				DFS(nr, nc, k, p + 100);
			}
			else {
				DFS(nr, nc, k, p + 500);
			}
			visited[nr][nc] = false;
		}
	}
}
int main() {
	DFS(0, 0, 1, 0);
	DFS(0, 0, 2, 0);
	return mn;
}