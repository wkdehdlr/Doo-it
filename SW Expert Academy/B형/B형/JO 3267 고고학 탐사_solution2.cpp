struct Position {
	int y, x, dir;
};


// *** user.cpp ***
#define MAXN 200
#define GOFORWARD 0
#define TURNRIGHT 1

extern void identify(int minimap[4][4]);
extern bool moving(int method);
Position que[160000];
int N, head, tail;
int check[4][4];
int arr[MAXN][MAXN][4];
int my_map[MAXN][MAXN];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
void encode(int x, int y, int k)
{
	if (k == 0) {//up
		for (int i = 0; i <= 3; ++i) {
			for (int j = 0; j <= 3; ++j) {
				arr[x][y][k] *= 3;
				arr[x][y][k] += my_map[x + i - 1][y + j - 1];
			}
		}
	}
	else if (k == 1) {//right
		for (int i = 0; i <= 3; ++i) {
			for (int j = 0; j <= 3; ++j) {
				arr[x][y][k] *= 3;
				arr[x][y][k] += my_map[x + j - 1][y - i + 2];
			}
		}
	}
	else if (k == 2) {//down
		for (int i = 0; i <= 3; ++i) {
			for (int j = 0; j <= 3; ++j) {
				arr[x][y][k] *= 3;
				arr[x][y][k] += my_map[x - i + 2][y - j + 2];
			}
		}
	}
	else if (k == 3) {//left
		for (int i = 0; i <= 3; ++i) {
			for (int j = 0; j <= 3; ++j) {
				arr[x][y][k] *= 3;
				arr[x][y][k] += my_map[x - j + 2][y + i - 1];
			}
		}
	}
}
int decode()
{
	int res = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			res *= 3;
			if (check[i][j] == -1)res += 2;
			else res += check[i][j];
		}
	}
	return res;
}
void userInit(int n, int Map[MAXN][MAXN]) {
	N = n;
	//최신 Map으로 갱신함
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (Map[i][j] == -1)my_map[i][j] = 2;
			else my_map[i][j] = Map[i][j];
		}
	}

	// 4*4 3진수로 변환
	for (int i = 1; i < n - 2; ++i) {
		for (int j = 1; j < n - 2; ++j) {
			for (int k = 0; k < 4; ++k) {
				arr[i][j][k] = 0;
				encode(i, j, k);
			}
		}
	}
}
void find(int res)
{
	tail = 0;
	for (int i = 1; i < N - 2; ++i) {
		for (int j = 1; j < N - 2; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (res == arr[i][j][k]) {
					que[tail].dir = k;
					que[tail].x = i;
					que[tail].y = j;
					tail++;
				}
			}
		}
	}
}
Position pos_search()
{
	identify(check);
	find(decode());
	while (tail != 1) {
		for (int k = 0; k < 4; ++k) {
			if (moving(0))break;
			moving(1);
			for (int i = 0; i < tail; ++i)que[i].dir = (que[i].dir + 1) % 4;
		}
		identify(check);
		int res = decode();
		head = 0;
		for (int i = 0; i < tail; ++i) {
			//후보들 이동
			int x = que[i].x + dr[que[i].dir];
			int y = que[i].y + dc[que[i].dir];
			if (res == arr[x][y][que[i].dir]) {
				que[head].x = x;
				que[head].y = y;
				que[head].dir = que[i].dir;
				head++;
			}
		}
		tail = head;
	}
	return { que[0].x,que[0].y,que[0].dir };
}