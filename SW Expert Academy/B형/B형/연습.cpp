const int DOC_MAX_SIZE = 1 << 8;
const int DOC_SIZE = 1 << 7;
typedef unsigned long long ULL;

char vdsd[5][DOC_SIZE][DOC_SIZE];
char pd[DOC_MAX_SIZE][DOC_MAX_SIZE];
char T[3][DOC_SIZE][DOC_SIZE];
ULL pd8[32][32], T8[3][16][16];

int chk[5], order[4], idx, len, vd, sr, sc, errLimit;
int dr[4] = { 0,0,1,1 };
int dc[4] = { 0,1,0,1 };
int rr[4] = { 0, };
int cc[4] = { 0, };
bool ok;

void userInit(int docSize)
{
	for (int i = 0; i < DOC_MAX_SIZE; ++i) {
		for (int j = 0; j < DOC_MAX_SIZE; ++j) {
			pd[i][j] = 0;
		}
	}
	for (int k = 0; k < 5; ++k) {
		for (int i = 0; i < DOC_SIZE; ++i) {
			for (int j = 0; j < DOC_SIZE; ++j) {
				vdsd[k][i][j] = 0;
			}
		}
	}
	idx = 0;
	len = docSize / 2;
	errLimit = (len* len) / 20;
	cc[1] = len;
	rr[2] = len;
	rr[3] = cc[3] = len;
	ok = false;
}
void shuffledVDSD(char document[][DOC_MAX_SIZE])
{
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			vdsd[idx][i][j] = document[i][j];
		}
	}
	idx++;
}
void set()
{
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < len; ++j) {
				pd[i + dr[k] * len][j + dc[k] * len] = vdsd[order[k]][i][j];
			}
		}
	}
	for (int i = 0; i < len * 2; ++i) {
		for (int j = 0; j < len * 2; ++j) {
			pd8[i / 8][j / 8] = pd8[i / 8][j / 8] * 2 + (pd[i][j] ? 1 : 0);
		}
	}
}
int diffBit(ULL n) 
{
	int i;
	for (i = 0; n != 0; i++) {
		n &= (n - 1);
	}
	return i;
}
int probing(ULL trr[][16], int r, int c) 
{
	int i, j, cnt = 0;
	for (i = 0; i < len / 8; ++i) {
		for (j = 0; j < len / 8; ++j) {
			cnt += diffBit(pd8[r + i][c + j] ^ trr[i][j]);
			if (20 * cnt > len * len)return 0;
		}
	}
	return 1;
}
int func(char document[][DOC_MAX_SIZE])
{
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			T[0][i][j] = document[i][j];
			T[1][i][j] = document[len - 1 - j][i];
			T[2][i][j] = document[j][len - 1 - i];

			T8[0][i / 8][j / 8] = T8[0][i / 8][j / 8] * 2 + (T[0][i][j] ? 1 : 0);
			T8[1][i / 8][j / 8] = T8[1][i / 8][j / 8] * 2 + (T[1][i][j] ? 1 : 0);
			T8[2][i / 8][j / 8] = T8[2][i / 8][j / 8] * 2 + (T[2][i][j] ? 1 : 0);
		}
	}
	for (int i = 0; i <= len / 8; i++) {
		for (int j = 0; j <= len / 8; j++) {
			if (probing(T8[0], i, j)) {
				return 1;
			}
			if (probing(T8[1], i, j)) {
				return 1;
			}
			if (probing(T8[2], i, j)) {
				return 1;
			}
		}
	}
	return 0;
}
int comp2(int k, int s, int r, int c, int er, int ec)
{
	for (; r < er; ++r) {
		for (int j = c; j < ec; ++j) {
			if (vdsd[s][r - rr[k]][j - cc[k]] != vdsd[vd][r - sr][j - sc])return 0;
		}
	}
	return 1;
}
int comp(int i, int ir, int ic, int j)
{
	for (int r = ir; r < len; ++r) {
		for (int c = ic; c < len; ++c) {
			if (vdsd[i][r][c] != vdsd[j][r - ir][c - ic])return 0;
		}
	}
	return 1;
}
int find_first(int i, int j)
{
	for (int r = 2; r < len - 2; ++r) {
		for (int c = 2; c < len - 2; ++c) {
			if (comp(i, r, c, j)) {
				sr = r;
				sc = c;
				return 1;
			}
		}
	}
	return 0;
}
int find_other(int k)
{
	if (k == 4)return 1;
	for (int i = 0; i < 5; ++i) {
		if (chk[i])continue;
		if (k == 1) {
			if (comp2(k, i, sr, len, len, sc + len)) {
				order[k] = i;
				chk[i] = 1;
				if (find_other(k + 1))return 1;
				chk[i] = 0;
			}
		}
		else if (k == 2) {
			if (comp2(k, i, len, sc, sr + len, len)) {
				order[k] = i;
				chk[i] = 1;
				if (find_other(k + 1))return 1;
				chk[i] = 0;
			}
		}
		else if (k == 3) {
			if (comp2(k, i, len, len, sr + len, sc + len)) {
				order[k] = i;
				chk[i] = 1;
				if (find_other(k + 1))return 1;
				chk[i] = 0;
			}
		}
	}
	return 0;
}
void init()
{
	for (int i = 0; i < 5; ++i)chk[i] = 0;
}
void find_pd()
{
	init();
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (i == j)continue;
			if (find_first(i, j)) {
				chk[i] = 1;
				chk[j] = 1;
				order[0] = i;
				vd = j;
				if (find_other(1))return;
				init();
			}
		}
	}
}
int verifyDocument(char document[][DOC_MAX_SIZE])
{
	if (!ok) {
		find_pd();
		set();
		ok = true;
	}
	if (func(document))return 1;
	return 0;
}