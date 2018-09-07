const int DOC_MAX_SIZE = 1 << 8;
const int DOC_SIZE = 1 << 7;

char vdsd[5][DOC_SIZE][DOC_SIZE];
char pd[DOC_MAX_SIZE][DOC_MAX_SIZE];
char rota[DOC_SIZE][DOC_SIZE];
unsigned long long map[32][32];
unsigned long long map2[16][16];

int chk[5], order[4], idx, len, vd, sr, sc;
int dr[4] = { 0,0,1,1 };
int dc[4] = { 0,1,0,1 };
int rr[4] = { 0, };
int cc[4] = { 0, };
bool ok;
void userInit(int docSize)
{
	for (int i = 0; i < 32; ++i)for (int j = 0; j < 32; ++j)map[i][j] = 0;

	for (int i = 0; i < DOC_MAX_SIZE; ++i) {
		for (int j = 0; j < DOC_MAX_SIZE; ++j) {
			pd[i][j] = 0;
		}
	}
	for (int k = 0; k < 5; ++k) {
		for (int i = 0; i < DOC_SIZE; ++i) {
			for (int j = 0; j < DOC_SIZE; ++j) {
				vdsd[k][i][j] = 0;
				rota[i][j] = 0;
			}
		}
	}
	idx = 0;
	len = docSize / 2;
	cc[1] = len;
	rr[2] = len;
	rr[3] = cc[3] = len;
	ok = false;
}
void shuffledVDSD(char document[][DOC_MAX_SIZE])
{
	//printf("===========\n");
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			vdsd[idx][i][j] = document[i][j];
			//	printf("%d", vdsd[idx][i][j] ? 1 : 0);
		}
		//printf("\n");
	}
	idx++;
}
void rot(int val, char document[][DOC_MAX_SIZE])
{
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (val == 0)rota[i][j] = document[i][j];
			else if (val == 1)rota[len - 1 - j][i] = document[i][j];
			else rota[j][len - 1 - i] = document[i][j];
		}
	}

	for (int i = 0; i < 16; ++i)for (int j = 0; j < 16; ++j)map2[i][j] = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			map2[i / 8][j / 8] = map2[i / 8][j / 8] * 2 + (rota[i][j] ? 1 : 0);
		}
	}
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
			map[i / 8][j / 8] = map[i / 8][j / 8] * 2 + (pd[i][j] ? 1 : 0);
		}
	}
}
int count(unsigned long long n) {
	int i;
	for (i = 0; n != 0; i++) {
		n &= (n - 1);
	}
	return i;
}
int func(char document[][DOC_MAX_SIZE])
{
	int nlen = len / 8;
	for (int r = 0; r <= nlen; ++r) {
		for (int c = 0; c <= nlen; ++c) {

			for (int k = 0; k < 3; ++k) {
				rot(k, document);
				int same = 0;
				unsigned long long tmp = 0;
				for (int i = 0; i < nlen; ++i) {
					for (int j = 0; j < nlen; ++j) {
						tmp = map[r + i][c + j] ^ map2[i][j];
						same += count(tmp);
					}
				}
				if (20 * same <= len * len)return 1;
			}
		}
	}
	return 0;
}
int comp2(int k, int s, int r, int c, int er, int ec, int v)
{
	for (; r < er; ++r) {
		for (int j = c; j < ec; ++j) {
			if (vdsd[s][r - rr[k]][j - cc[k]] != vdsd[v][r - sr][j - sc])return 0;
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
int find_other()
{
	for (int k = 1; k < 3; ++k) {
		for (int i = 0; i < 5; ++i) {
			if (chk[i])continue;
			if (k == 1) {
				if (comp2(k, i, sr, len, len, sc + len, vd)) {
					order[k] = i;
					chk[i] = 1;
				}
			}
			else if (k == 2) {
				if (comp2(k, i, len, sc, sr + len, len, vd)) {
					order[k] = i;
					chk[i] = 1;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 5; ++i) {
		if (chk[i] == 0)cnt++;
	}
	if (cnt != 1)return 0;

	for (int i = 0; i < 5; ++i) {
		if (chk[i])continue;
		order[3] = i;
		chk[i] = 1;
	}
	return 1;
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
				if (find_other())return;
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