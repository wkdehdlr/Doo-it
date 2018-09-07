#pragma warning(disable : 4996)
#include<cstdio>

const int DOC_MAX_SIZE = 1 << 8;
const int RANDMOD = ~(1 << 31);
const int RANDMULTI = 0x343fd;
const int RANDADD = 0x269ec3;

extern void userInit(int docSize);
extern void shuffledVDSD(char document[][DOC_MAX_SIZE]);
extern int verifyDocument(char document[][DOC_MAX_SIZE]);


static int Len;
static int Half;
static int verifyCnt;
static char PD[DOC_MAX_SIZE][DOC_MAX_SIZE];
static char VDSD[DOC_MAX_SIZE][DOC_MAX_SIZE];
static int row[6], col[6];
static unsigned int randSeed = 3;


static int getRandNum(void) {
	randSeed = randSeed * RANDMULTI + RANDADD;
	return (randSeed & RANDMOD) >> 16;
}

inline void Swap(int&a, int&b) { int t = a; a = b; b = t; }

static void generateDocument() {
	int i, j, k = 0;
	for (i = 0; i < Len; ++i) {
		for (j = 0; j < Len; ++j) {
			PD[i][j] = getRandNum() & 1;
			//printf("%d", PD[i][j] ? 1 : 0);
		}
		//printf("\n");
	}
	//printf("\n");
	for (i = 0; i < Len; i += Half) {
		for (j = 0; j < Len; j += Half) {
			row[k] = i;
			col[k++] = j;
		}
	}

	row[4] = getRandNum() % (Half - 4) + 2;
	col[4] = getRandNum() % (Half - 4) + 2;

	for (i = 0; i < 5; ++i) {
		j = getRandNum() % 5;
		Swap(row[i], row[j]);
		Swap(col[i], col[j]);
	}

	for (k = 0; k < 5; k++) {
		for (i = 0; i < Half; i++) {
			for (j = 0; j < Half; ++j) {
				VDSD[i][j] = PD[row[k] + i][col[k] + j];
			}
		}
		shuffledVDSD(VDSD);
	}
}

static void scratchVDSD() {
	int stRow = getRandNum() % (Half / 2 * 3);
	int stCol = getRandNum() % (Half / 2 * 3);
	int rotate = getRandNum() % 3;
	int ratio = getRandNum() % 12 + 1;
	stRow = stRow & 0xfff8;
	stCol = stCol & 0xfff8;

	if (stRow > Half)stRow = Half;
	if (stCol > Half)stCol = Half;

	for (int i = 0; i < Len; ++i) {
		for (int j = 0; j < Len; ++j) {
			VDSD[i][j] = 0;
		}
	}

	for (int i = 0; i < Half; ++i) {
		for (int j = 0; j < Half; ++j) {
			int val = PD[i + stRow][j + stCol];
			if (rotate == 0)VDSD[i][j] = val;
			else if (rotate == 1)VDSD[Half - 1 - j][i] = val;
			else VDSD[j][Half - 1 - i] = val;
		}
	}

  for (int i = 0; i < (Half*Half*ratio) / 100; ++i) {
		int r = getRandNum() % Half;
		int c = getRandNum() % Half;
		VDSD[r][c] = 1 - VDSD[r][c];
	}

  /*printf("================\n");
  for (int i = 0; i < Half; ++i) {
	  for (int j = 0; j < Half; ++j) {
		  printf("%d", VDSD[i][j] ? 1 : 0);
	  }
	  printf("\n");
  }*/
}

int main()
{
	int TC, totalscore = 0;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; ++i) {
		scanf("%d%d%d", &randSeed, &Len, &verifyCnt);
		Half = Len / 2;
		userInit(Len);
		generateDocument();

		int answer, response;
		int correcCount = 0;
		
		for (int j = 0; j < verifyCnt; ++j) {
			scratchVDSD();
			response = verifyDocument(VDSD);
			scanf("%d", &answer);
			correcCount += (answer == response);
		}

		int score = 100 * (correcCount == verifyCnt);
		printf("#%d %d\n", i, score);
		totalscore += score;
	}

	printf("Total Score = %d\n", totalscore / TC);
	return 0;
}