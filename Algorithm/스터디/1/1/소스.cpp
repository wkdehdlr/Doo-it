#pragma warning(disable : 4996)
#include <cstdio>
#include <memory.h>
#include <vector>

using namespace std;

struct node { int x, y; };

vector<node> v;
int mat[9][9];
int domi[10][10];
int xl[9], yl[9], sl[9];
int ans, si;
int temp = 0;

int st(int i, int j) { return i / 3 * 3 + j / 3; }

void go(int o) {
	if (o == si) ans = 1;
	if (ans) return;

	int x = v[o].x, y = v[o].y;
	int ttl, tl;

	if (mat[x][y]) go(o + 1);
	ttl = xl[x] | yl[y] | sl[st(x, y)];

	for (int i = 1; i < 10; i++) {
		if (!(ttl & (1 << i))) {
			mat[x][y] = i;
			xl[x] |= (1 << i);
			yl[y] |= (1 << i);
			sl[st(x, y)] |= (1 << i);

			if (x + 1 < 9 && !mat[x + 1][y]) {
				tl = xl[x + 1] | yl[y] | sl[st(x + 1, y)];
				for (int j = 1; j < 10; j++)
					if (!(tl & (1 << j)) && !domi[i][j]) {
						mat[x + 1][y] = j;
						xl[x + 1] |= (1 << j);
						yl[y] |= (1 << j);
						sl[st(x + 1, y)] |= (1 << j);
						domi[i][j] = domi[j][i] = 1;

						go(o + 1);
						if (ans) return;

						mat[x + 1][y] = 0;
						xl[x + 1] ^= (1 << j);
						yl[y] ^= (1 << j);
						sl[st(x + 1, y)] ^= (1 << j);
						domi[i][j] = domi[j][i] = 0;
					}
			}

			if (y + 1 < 9 && !mat[x][y + 1]) {
				tl = xl[x] | yl[y + 1] | sl[st(x, y + 1)];
				for (int j = 1; j < 10; j++)
					if (!(tl & (1 << j)) && !domi[i][j]) {
						mat[x][y + 1] = j;
						xl[x] |= (1 << j);
						yl[y + 1] |= (1 << j);
						sl[st(x, y + 1)] |= (1 << j);
						domi[i][j] = domi[j][i] = 1;

						go(o + 1);
						if (ans) return;

						mat[x][y + 1] = 0;
						xl[x] ^= (1 << j);
						yl[y + 1] ^= (1 << j);
						sl[st(x, y + 1)] ^= (1 << j);
						domi[i][j] = domi[j][i] = 0;
					}
			}

			mat[x][y] = 0;
			xl[x] ^= (1 << i);
			yl[y] ^= (1 << i);
			sl[st(x, y)] ^= (1 << i);
		}
	}
}

int main() {
	int t = 0;
	node tv;

	while (++t) {
		int n, a, c;
		char b[3], d[3];
		scanf("%d", &n);

		if (!n) break;

		memset(mat, 0, sizeof(mat));
		memset(domi, 0, sizeof(domi));
		memset(xl, 0, sizeof(xl));
		memset(yl, 0, sizeof(yl));
		memset(sl, 0, sizeof(sl));

		v.clear();
		ans = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d %s %d %s", &a, b, &c, d);
			mat[b[0] - 'A'][b[1] - '1'] = a;
			mat[d[0] - 'A'][d[1] - '1'] = c;
			domi[a][c] = domi[c][a] = 1;
		}

		for (int i = 1; i < 10; i++) {
			domi[i][i] = 1;
			scanf("%s", b);
			mat[b[0] - 'A'][b[1] - '1'] = i;
		}

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) {
				xl[i] |= (1 << mat[i][j]);
				yl[j] |= (1 << mat[i][j]);
				sl[st(i, j)] |= (1 << mat[i][j]);

				if (!mat[i][j]) {
					tv.x = i, tv.y = j;
					v.push_back(tv);
				}
			}

		si = v.size();
		go(0);

		printf("Puzzle %d\n", t);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d", mat[i][j]);
			printf("\n");
		}
	}
}
