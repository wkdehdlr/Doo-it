int N, M, empty, idx;
int map[32][32], hint[1000][2][2], chk[1000];
char q[4][4];

extern void query(char sector[][4]);

void encode(char board[][65])
{
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 32; ++j) {
			if (i == 0 || i == M - 1 || j == 0 || j == M - 1)map[i][j] = 0;
			else map[i][j] = -1;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] == '*')continue;
			map[i / 2][j / 2] = map[i / 2][j / 2] * 16 + board[i][j] - 'A';
		}
	}
}
void encode(int arr[][2])
{
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			arr[i / 2][j / 2] = arr[i / 2][j / 2] * 16 + q[i][j] - 'A';
		}
	}
}
int check()
{
	for (int i = 0; i < idx; ++i) {
		if (hint[i][0][0] == hint[idx][0][0] &&
			hint[i][1][0] == hint[idx][1][0] &&
			hint[i][0][1] == hint[idx][0][1] &&
			hint[i][1][1] == hint[idx][1][1])return 1;
	}
	return 0;
}
int update(int arr[][2], int sr, int sc, int len)
{
	for (int i = sr; i < sr + len; ++i) {
		for (int j = sc; j < sc + len; ++j) {

			int cnt = 0;
			for (int r = 0; r < 2; ++r) {
				for (int c = 0; c < 2; ++c) {
					if (map[i + r][c + j] == arr[r][c])cnt++;
				}
			}
			if (cnt == 4)return 1;
			if (cnt < 2)continue;

			for (int r = 0; r < 2; ++r) {
				for (int c = 0; c < 2; ++c) {
					if (map[i + r][c + j] < 0) {
						map[i + r][c + j] = arr[r][c];
						empty--;
					}
				}
			}

			for (int k = 0; k < idx; ++k)if (chk[k] == 0)chk[k] = update(hint[k], i - 1, j - 1, 3);
			return 1;
		}
	}
	return 0;
}
void decode(char board[][65])
{
	for (int i = N - 1; i >= 0; --i) {
		for (int j = N - 1; j >= 0; --j) {
			board[i][j] = map[i / 2][j / 2] % 16 + 'A';
			map[i / 2][j / 2] /= 16;
		}
	}
}
void repair(int n, int m, char board[][65])
{
	N = n;
	M = n / 2;
	empty = (M - 2)*(M - 2);
	idx = 0;
	encode(board);
	for (int i = 0; i < 1000; ++i)chk[i] = 0;
	for (int i = 0; i < m; ++i) {
		query(q);
		encode(hint[idx]);
		if (check())continue;
		chk[idx] = update(hint[idx], 0, 0, M - 1);
		idx++;
		if (empty * 20 <= M * M)break;
	}
	decode(board);
}