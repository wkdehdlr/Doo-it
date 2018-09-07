#ifndef DOC_MAX_SIZE 
#define DOC_MAX_SIZE  (256) 
#endif 

typedef unsigned long long ULL;
const int LM = 257;

int N, M, A[LM][LM], C[5][LM][LM], S[5][LM][LM];
int cnt, per[5], used[5], errLimit;
int(*srr)[LM], (*crr)[LM];
ULL A8[LM][LM], T8[3][LM][LM];
int AS8[LM][LM], T[3][LM][LM], TS8[3][LM][LM];

int popCnt[1 << 16], popCntFlag;
const int MOD = (1 << 16) - 1;

void userInit(int docSize) {
	N = docSize;
	M = N / 2;
	cnt = 0;
	errLimit = M * M / 20; /// 틀린 개수의 한계 5% 
	int i;
	for (i = 0; i < 5; ++i) per[i] = used[i] = 0; /// 순열 
	if (popCntFlag == 0) {
		popCntFlag = 1;
		for (i = 1; i < (1 << 16); ++i) {
			popCnt[i] = popCnt[i >> 1] + (i & 1);
		}
	}
}

int sumCheck(int sum, int arr[][LM], int sr, int sc, int er, int ec) {
	return sum == (arr[er][ec] - arr[er][sc] - arr[sr][ec] + arr[sr][sc]);
}

int comp(int si, int sj, int ei, int ej, int arr[][LM], int sr, int sc) {
	for (int i = 0; i <= ei - si; ++i) {
		for (int j = 0; j <= ej - sj; ++j) {
			if (crr[si + i][sj + j] != arr[sr + i][sc + j]) return 0;
		}
	}
	return 1;
}

bool check() {
	srr = S[per[4]];
	crr = C[per[4]];
	int i, j, er, ec, a, b, c, d;
	for (i = 2; i<M - 2; ++i) {
		for (j = 2; j<M - 2; ++j) {
			er = M - i, ec = M - j;
			a = srr[er][ec], b = srr[er][M] - a;
			c = srr[M][ec] - a, d = srr[M][M] - a - b - c;
			if (sumCheck(a, S[per[0]], i, j, M, M) == 0) continue;
			if (sumCheck(b, S[per[1]], i, 0, M, j) == 0) continue;
			if (sumCheck(c, S[per[2]], 0, j, i, M) == 0) continue;
			if (d != S[per[3]][i][j]) continue;

			if (comp(1, 1, er, ec, C[per[0]], i + 1, j + 1) == 0) continue;
			if (comp(1, ec + 1, er, M, C[per[1]], i + 1, 1) == 0) continue;
			if (comp(er + 1, 1, M, ec, C[per[2]], 1, j + 1) == 0) continue;
			if (comp(er + 1, ec + 1, M, M, C[per[3]], 1, 1) == 0) continue;
			return true;
		}
	}
	return false;
}

int dfs(int lev) {
	if (lev>4) {
		if (check()) return 1;
		return 0;
	}
	for (int i = 0; i < 5; ++i)if (used[i] == 0) {
		per[lev] = i;
		used[i] = 1;
		if (dfs(lev + 1)) return 1;
		used[i] = 0;
	}
	return 0;
}

ULL getCode(int arr[][LM], int r, int c, int&sumtg) {
	ULL ret = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			ret = ret * 2 + arr[r + i][c + j];
			/// sumtg += arr[r + i][c + j]; 
		}
	}
	return ret;
}

void shuffledVDSD(char document[][DOC_MAX_SIZE]) {
	int i, j, k;
	for (i = 1; i <= M; ++i) {
		for (j = 1; j <= M; ++j) {
			C[cnt][i][j] = k = document[i - 1][j - 1];
			S[cnt][i][j] = S[cnt][i - 1][j] + S[cnt][i][j - 1]
				- S[cnt][i - 1][j - 1] + k;
		}
	}
	cnt++;
	if (cnt>4) {
		if (dfs(0)) {
			int r, c, i, j, k;
			for (k = 0; k < 4; ++k) {
				r = k / 2 * M, c = k % 2 * M;
				for (i = 1; i <= M; ++i) { /// 문서 복원 
					for (j = 1; j <= M; ++j) {
						A[r + i][c + j] = C[per[k]][i][j];
					}
				}
			}
			for (r = i = 1; i < N; i += 8, r++) { /// 8*8(64) 해시 문서 만들기 
				for (c = j = 1; j < N; j += 8, c++) {
					A8[r][c] = getCode(A, i, j, AS8[r][c]);
					AS8[r][c] = AS8[r - 1][c] + AS8[r][c - 1] - AS8[r - 1][c - 1];
				}
			}
			return;
		}
	}
}

int diffBit(ULL a) {
	int ret = 0;
	for (; a; a >>= 16) ret += popCnt[a & MOD];
	return ret;
}

int probing(ULL trr[][LM], int r, int c) {
	int i, j, cnt = 0;
	for (i = 0; i < M / 8; ++i) {
		for (j = 0; j < M / 8; ++j) {
			cnt += diffBit(A8[r + i][c + j] ^ trr[i + 1][j + 1]);
			if (cnt>errLimit) return 0;
		}
	}
	return 1;
}

/*
void output(int arr[][LM], int r, int c) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			printf("%d ", arr[r + i][c + j]);
		}
		puts("");
	}
	puts("");
}*/


inline int Abs(int a) { return a < 0 ? -a : a; }
int verifyDocument(char document[][DOC_MAX_SIZE]) {
	int i, j, r = 1, c = 1;
	for (i = 0; i < M; ++i) {
		for (j = 0; j < M; ++j) {
			T[0][i + 1][j + 1] = document[i][j];
			T[1][i + 1][j + 1] = document[M - 1 - j][i];
			T[2][i + 1][j + 1] = document[j][M - 1 - i];
		}
	}
	//output(A, 1, 9); 
	//output(T[1], 1, 1); 
	for (r = i = 1; i < M; i += 8, r++) {
		for (c = j = 1; j < M; j += 8, c++) {
			T8[0][r][c] = getCode(T[0], i, j, TS8[0][r][c]);
			//TS8[0][r][c] = TS8[0][r - 1][c] + TS8[0][r][c - 1] - TS8[0][r - 1][c - 1]; 
			T8[1][r][c] = getCode(T[1], i, j, TS8[1][r][c]);
			//TS8[1][r][c] = TS8[1][r - 1][c] + TS8[1][r][c - 1] - TS8[1][r - 1][c - 1]; 
			T8[2][r][c] = getCode(T[2], i, j, TS8[2][r][c]);
			//TS8[2][r][c] = TS8[2][r - 1][c] + TS8[2][r][c - 1] - TS8[2][r - 1][c - 1]; 
		}
	}
	for (i = 1; i <= M / 8 + 1; i++) {
		for (j = 1; j <= M / 8 + 1; j++) {
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