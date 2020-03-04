#pragma warning(disable : 4996)
#include <cstdio>

#define MAX_SIZE 1000
#define LENGTH 20

static int AN, A[MAX_SIZE][MAX_SIZE];
static int BM, B[LENGTH][LENGTH];
static int limit;
static int used[MAX_SIZE][MAX_SIZE];

static unsigned int seed;
static unsigned int myRand() {
	seed = 22695477 * seed + 1;
	return seed >> 16;
}

extern void init(int, int[][MAX_SIZE], int);
extern int query(int[][LENGTH], int[]);

static void makeArr() {
	for (int i = 0; i < AN; ++i)for (int j = 0; j < AN; ++j) {
		A[i][j] = myRand() & 1;
	}
}

static int rot;
static int makeBrr(int arr[], int un) {
	int sr, sc, mr = -1, mc = -1;
	int i, j;
	int m = 0;

	rot = myRand() % 4;

	while (1) {
		sr = myRand() % (limit + 1);
		sc = myRand() % (limit + 1);
		if (used[sr][sc] < un) break;
	}

	for (i = 0; i < BM; ++i)for (j = 0; j < BM; ++j) m += A[sr + i][sc + j];
	m = myRand() % m + 1;

	for (i = 0; i < BM; ++i)for (j = 0; j < BM; ++j) {
		if (A[sr + i][sc + j] && m) {
			m--, mr = sr + i, mc = sc + j;
		}

		/// rotate clockwise
		switch (rot) {
		case 0: B[i][j] = A[sr + i][sc + j]; break; //   0
		case 1: B[j][BM - 1 - i] = A[sr + i][sc + j]; break; //  90
		case 2: B[BM - 1 - i][BM - 1 - j] = A[sr + i][sc + j]; break; // 180
		case 3: B[BM - 1 - j][i] = A[sr + i][sc + j]; break; // 270
		}
	}
	if (mr < 0) return 1;
	arr[0] = sr, arr[1] = sc, arr[2] = mr, arr[3] = mc;
	mr -= sr, mc -= sc;
	if (rot == 0)      B[mr][mc] = 9;
	else if (rot == 1) B[mc][BM - 1 - mr] = 9;
	else if (rot == 2) B[BM - 1 - mr][BM - 1 - mc] = 9;
	else if (rot == 3) B[BM - 1 - mc][mr] = 9;

	return 0;
}

static int run(int usedCount) {

	int ans[4] = { 0 }, userAns[4] = { 0 };
	while (makeBrr(ans, usedCount));

	int userRot = query(B, userAns);
	if (userRot < 0 || userRot>3) return 0;

	int userR = userAns[2], userC = userAns[3];
	int sr = ans[0], sc = ans[1];

	/// alternative answer check
	if (userR != ans[2] || userC != ans[3]) {
		userR = userAns[0];
		userC = userAns[1];
		if (userR<0 || userR>limit || userC<0 || userC>limit)
			return 0;
		for (int i = 0; i < BM; ++i)for (int j = 0; j < BM; ++j) {
			int r = i, c = j;
			switch (userRot) {
			case 0: r = i, c = j;       break;
			case 1: r = j, c = BM - 1 - i;  break;
			case 2: r = BM - 1 - i, c = BM - 1 - j;  break;
			case 3: r = BM - 1 - j, c = i;       break;
			}
			if (A[userR + i][userC + j] != !!B[r][c])
				return 0;
		}
		sr = userR, sc = userC;
	}
	used[sr][sc] = usedCount;
	return 100;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int TC, i, j, Q, usedCount = 0;
	scanf("%d", &TC);
	for (i = 1; i <= TC; ++i) {
		scanf("%d %d %u %d", &AN, &BM, &seed, &Q);
		limit = AN - BM;
		int total = 0;
		makeArr();
		init(AN, A, BM);
		for (j = 1; j <= Q; ++j) {
			int sc = run(++usedCount);
			total += sc;
		}
		printf("#case %d : %d\n", i, total / Q);
	}
	return 0;
}