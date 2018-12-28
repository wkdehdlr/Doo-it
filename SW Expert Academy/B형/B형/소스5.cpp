#define GOFORWARD 0 
#define TURNRIGHT 1 

#define MAXN 200 

#define UP 0 
#define RIGHT 1 
#define DOWN 2 
#define LEFT 3 

struct Position {
	int y, x, dir;
} que[160000];

extern void identify(int minimap[4][4]);
extern bool moving(int method);

int N, key[200][200][4], map[200][200];
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

void encode(int sy, int sx) {
	int y, x, d;
	for (d = 0; d < 4; d++) key[sy][sx][d] = 0;
	for (y = sy - 1; y <= sy + 2; ++y)
		for (x = sx - 1; x <= sx + 2; ++x)
			key[sy][sx][0] = key[sy][sx][0] * 3 + map[y][x];
	for (x = sx + 2; x >= sx - 1; --x)
		for (y = sy - 1; y <= sy + 2; ++y)
			key[sy][sx][1] = key[sy][sx][1] * 3 + map[y][x];
	for (y = sy + 2; y >= sy - 1; --y)
		for (x = sx + 2; x >= sx - 1; --x)
			key[sy][sx][2] = key[sy][sx][2] * 3 + map[y][x];
	for (x = sx - 1; x <= sx + 2; ++x)
		for (y = sy + 2; y >= sy - 1; --y)
			key[sy][sx][3] = key[sy][sx][3] * 3 + map[y][x];
}

void userInit(int n, int Map[MAXN][MAXN]) {
	N = n;
	for (int y = 0; y < N; ++y) for (int x = 0; x < N; ++x) {
		map[y][x] = Map[y][x];
		if (map[y][x] == -1) map[y][x] = 2;
	}

	for (int y = 1; y <= N - 3; ++y) for (int x = 1; x <= N - 3; ++x)
		encode(y, x);
}

int query()
{
	int bike[4][4], bikekey = 0;
	identify(bike);
	for (int y = 0; y < 4; ++y) for (int x = 0; x < 4; ++x) {
		if (bike[y][x] == -1) bike[y][x] = 2;
		bikekey = bikekey * 3 + bike[y][x];
	}
	return bikekey;
}

Position pos_search()
{
	int bikekey = query();
	int y, x, d, i, j, head, tail = 0;
	for (y = 1; y <= N - 3; ++y) {
		for (x = 1; x <= N - 3; ++x) {
			for (d = 0; d < 4; d++) {
				if (key[y][x][d] == bikekey) {
					que[tail].y = y, que[tail].x = x, que[tail].dir = d;
					tail++;
				}
			}
		}
	}

	while (tail != 1) {
		for (i = 0; i < 4; i++) {
			if (moving(0)) break;
			moving(1);
			for (j = 0; j < tail; j++) que[j].dir = (que[j].dir + 1) % 4;
		}
		bikekey = query();
		head = 0;
		for (i = 0; i < tail; i++) {
			d = que[i].dir;
			y = que[i].y + dy[d], x = que[i].x + dx[d];
			if (key[y][x][d] == bikekey) {
				que[head].y = y, que[head].x = x, que[head].dir = d;
				head++;
			}
		}
		tail = head;
	}
	return que[0];
}