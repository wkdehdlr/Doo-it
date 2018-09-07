#include<cstdio>
const int DOC_MAX_SIZE = 1 << 8;
const int DOC_SIZE = 1 << 7;

char rotate[DOC_SIZE][DOC_SIZE];
char vdsd[5][DOC_SIZE][DOC_SIZE];
char pd[DOC_MAX_SIZE][DOC_MAX_SIZE];
int chk[5], order[4], idx, len, vd, sr, sc;
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

void set()
{
	//printf("+++++++++++++++++++++++++++++++\n");
	//order[0] = 2;
	//order[1] = 1;
	//order[2] = 4;
	//order[3] = 0;
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < len; ++j) {
				pd[i + dr[k] * len][j + dc[k] * len] = vdsd[order[k]][i][j];
				//if(k==1)printf("%d", vdsd[order[k]][i][j] ? 1 : 0);
			}
			//if(k==1)printf("\n");
		}
	}
	/*for (int i = 0; i < 2 * len; ++i) {
		for (int j = 0; j < 2 * len; ++j) {
			printf("%d", pd[i][j] ? 1 : 0);;
		}
		printf("\n");
	}
	printf("\n");*/
	//printf("+++++++++++++++++++++++++++++++\n");
}
void rot(int val, char document[][DOC_MAX_SIZE])
{
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (val == 0)rotate[i][j] = document[i][j];
			else if (val == 1)rotate[len - 1 - j][i] = document[i][j];
			else rotate[j][len - 1 - i] = document[i][j];
		}
	}
}
int func(char document[][DOC_MAX_SIZE])
{
	int a = len / 8;
	for (int r = 0; r <= a; ++r) {
		for (int c = 0; c <= a; ++c) {

			for (int k = 0; k < 3; ++k) {
				//rot(k, document);
				int flag = false;
				int same = 0;
				for (int i = 0; i < len; ++i) {
					for (int j = 0; j < len; ++j) {
						if (k == 0) {
							if (pd[8 * r + i][8 * c + j] != document[i][j])same++;
						}
						else if (k == 1) {
							if (pd[8 * r + len - 1 - j][8 * c + i] != document[i][j])same++;
						}
						else {
							if (pd[8 * r + j][8 * c + len - 1 - i] != document[i][j])same++;
						}

						/*if ((int)(((double)same / (double)(len*len)) * 100) > 5) {
							flag = true;
							break;
						}*/
						if (20 * same > len * len) {
							flag = true;
							break;
						}
					}
					if (flag)break;
				}
				if (flag)continue;
				if (20 * same <= len * len)return 1;
//				if ((int)(((double)same / (double)(len*len)) * 100) <= 5)return 1;
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
/*
int find_other(int)
{
	for (int k = 1; k < 3; ++k) {
		for (int i = 0; i < 5; ++i) {
			if (chk[i])continue;
			if (k == 1) {
				if (comp2(k, i, sr, len, len, sc + len, vd)) {
					order[k] = i;
					chk[i] = 1;
					break;
				}
			}
			else if (k == 2) {
				if (comp2(k, i, len, sc, sr + len, len, vd)) {
					order[k] = i;
					chk[i] = 1;
					break;
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
}*/
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