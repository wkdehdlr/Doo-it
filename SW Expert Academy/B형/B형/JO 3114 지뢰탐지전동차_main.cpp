#include <stdio.h>
#include <stdlib.h>



#define MAX_N 50
#define FOWARD 0
#define BACKWARD 1
#define RIGHT 2
#define LEFT 3
#define END 4
#define LIMIT 10000



static int N;
extern void init(int N);
extern int action(int input[12]);



/*  RIGHT, DOWN, LEFT, UP */
static int dx[4] = { 1, 0, -1, 0 };
static int dy[4] = { 0, 1, 0, -1 };



const int view[4][12][2] =
{
	{
		// RIGHT
		{ 4, 0 },{ 3, -1 },{ 3, 0 },{ 3, 1 },{ 2, -2 },{ 2, -1 },{ 2, 0 },{ 2, 1 },{ 2, 2 },{ 1, -1 },{ 1, 0 },{ 1, 1 }
	},
	{
		// DOWN
		{ 0, 4 },{ 1, 3 },{ 0, 3 },{ -1, 3 },{ 2, 2 },{ 1, 2 },{ 0, 2 },{ -1, 2 },{ -2, 2 },{ 1, 1 },{ 0, 1 },{ -1, 1 }
	},
	{
		// LEFT
		{ -4, 0 },{ -3, 1 },{ -3, 0 },{ -3, -1 },{ -2, 2 },{ -2, 1 },{ -2, 0 },{ -2, -1 },{ -2, -2 },{ -1, 1 },{ -1, 0 },{ -1, -1 }
	},
	{
		// UP
		{ 0, -4 },{ -1, -3 },{ 0, -3 },{ 1, -3 },{ -2, -2 },{ -1, -2 },{ 0, -2 },{ 1, -2 },{ 2, -2 },{ -1, -1 },{ 0, -1 },{ 1, -1 }
	}
};



static int play()
{
	int score, posX, posY, dir, posible;
	int lookX, lookY;
	int viewmap[12], map[MAX_N + 8][MAX_N + 8];

	for (int i = 0; i < N + 8; i++)
		for (int j = 0; j < N + 8; j++)
		{
			map[i][j] = 1;
		}


	scanf("%d", &posible);
	for (int i = 4; i < N + 4; i++)
		for (int j = 4; j < N + 4; j++)
			scanf("%d", &map[i][j]);

	map[4][4] = map[N + 3][N + 3] = 0;

	posY = posX = 4;
	dir = 0;
	score = 0;

	while (score < LIMIT)
	{
		for (int i = 0; i < 12; i++)
		{
			lookX = posX + view[dir][i][0];
			lookY = posY + view[dir][i][1];
			viewmap[i] = map[lookY][lookX];
		}

		switch (action(viewmap))
		{
		case FOWARD:
			if (map[posY + dy[dir]][posX + dx[dir]] == 0)
			{
				posY += dy[dir];
				posX += dx[dir];
			}
			break;

		case BACKWARD:
			if (map[posY - dy[dir]][posX - dx[dir]] == 0)
			{
				posY -= dy[dir];
				posX -= dx[dir];
			}
			break;

		case RIGHT:
			dir = (dir + 1) % 4;
			break;

		case LEFT:
			dir = (dir + 3) % 4;
			break;

		case END:
			return (posible == 0) ? score : LIMIT;
		}

		if (posX == N + 3 && posY == N + 3)
			break;

		score++;
	}
	return score;
}



int main()
{
	int T;
	int total_score = 0;

	scanf("%d", &T);

	for (int t = 1; t <= T; ++t)
	{
		scanf("%d", &N);

		init(N);
		int score = play();

		printf("#%d %d\n", t, score);
		total_score += score;
	}

	printf("Total Move Count = %d\n", total_score);
	return 0;
}