#pragma warning(disable : 4996)
#include <stdio.h>

#define MAXBEE        7 
#define MAXSIZE      100

struct COORD {
	int y, x;
};

static COORD bee[MAXBEE];

static int pattern[MAXSIZE][MAXSIZE];

static int width, height, N, M, Max_movecnt;

static bool okay;
static int movecnt, total_movecnt;
static int score;



static const int dy[5] = { 0, 0, 1, 0, -1 };
static const int dx[5] = { 0, 1, 0, -1, 0 };



extern void init(int N, COORD bee[MAXBEE]);
extern COORD make_pattern(int height, int width, int pattern[MAXSIZE][MAXSIZE]);



int moveBee(int dir[MAXBEE]) {
	if (!score)
		return score;

	if (++movecnt > Max_movecnt)
		return score = 0;

	for (int i = 0; i < N; ++i) {
		if (dir[i] < 0 || dir[i] > 4) {
			return score = 0;
		}

		bee[i].y += dy[dir[i]];
		bee[i].x += dx[dir[i]];

		if (bee[i].y < 0 || bee[i].y >= MAXSIZE || bee[i].x < 0 || bee[i].x >= MAXSIZE)
			return score = 0;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j)
			if (dir[i] * dir[j] > 0 && bee[i].y == bee[j].y && bee[i].x == bee[j].x)
				return score = 0;
	}

	return 1;
}

static bool Matched(COORD start) {
	for (int i = 0; i < N; ++i) {
		int y = bee[i].y - start.y;
		int x = bee[i].x - start.x;

		if (y < 0 || y >= height || x < 0 || x >= width || pattern[y][x] == 0)
			return false;
		--pattern[y][x];
	}
	return true;
}

static void play()
{
	COORD patten_start;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%d %d", &bee[i].y, &bee[i].x);

	init(N, bee);

	okay = true;

	total_movecnt = 0;

	for (int i = 0; i < M; ++i) {
		movecnt = 0;
		int flower_pattern[MAXSIZE][MAXSIZE];

		scanf("%d %d %d", &height, &width, &Max_movecnt);

		for (int y = 0; y < height; ++y)
			for (int x = 0; x < width; ++x) {
				scanf("%d", &pattern[y][x]);
				flower_pattern[y][x] = pattern[y][x];
			}

		COORD patten_start = make_pattern(height, width, flower_pattern);

		if (!okay || movecnt > Max_movecnt || !Matched(patten_start))
			score = 0;
	}

	total_movecnt += movecnt;
}

int main()
{
	int T;

	scanf("%d", &T);

	int totalscore = 0, totalcount = 0;
	for (int t = 1; t <= T; ++t) {
		score = 100;
		play();
		printf("#%d : %d \n", t, total_movecnt);
		totalscore += score;
	}
	printf("\nscore = %d\n", totalscore);
	return 0;
}