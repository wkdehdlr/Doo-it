#define MAX_N 50
#define FOWARD 0
#define BACKWARD 1
#define RIGHT 2
#define LEFT 3
#define END 4
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int view[4][12][2] =
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
int map[MAX_N + 8][MAX_N + 8];
int dir = 0;
int posX = 0;
int posY = 0;

void init(int N)
{

}

int action(int input[12])
{
	int lookX, lookY;
	for (int i = 0; i < 12; i++)
	{
		lookX = posX + view[dir][i][0];
		lookY = posY + view[dir][i][1];
		map[lookY][lookX] = input[i];
	}
}