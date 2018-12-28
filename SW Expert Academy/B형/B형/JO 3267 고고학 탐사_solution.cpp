struct Position {
	int y, x, dir;
};


// *** user.cpp ***
#define MAXN 200
#define GOFORWARD 0
#define TURNRIGHT 1

extern void identify(int minimap[4][4]);
extern bool moving(int method);
Position ans;
bool first;
int now_x, now_y, now_dir;
int N;
int check[4][4];
int arr[MAXN][MAXN][4];
int my_map[MAXN][MAXN];
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
	first = true;
}
int find(int res)
{
	int cnt = 0;
	for (int i = 1; i < N - 2; ++i) {
		for (int j = 1; j < N - 2; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (res == arr[i][j][k]) {
					ans.dir = k;
					ans.x = j;
					ans.y = i;
					cnt++;
				}
				if (cnt == 2)return 0;
			}
		}
	}
	return 1;
}
int find2(int res)
{
	int sx, ex, sy, ey;
	now_x == 1 ? sx = 1 : sx = now_x - 1;
	now_x == N - 3 ? ex = N - 3 : ex = now_x + 1;
	now_y == 1 ? sy = 1 : sy = now_y - 1;
	now_y == N - 3 ? ey = N - 3 : ey = now_y + 1;
	int cnt = 0;
	for (int i = sx; i <= ex; ++i) {
		for (int j = sy; j <= ey; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (res == arr[i][j][k]) {
					ans.dir = k;
					ans.x = j;
					ans.y = i;
					cnt++;
				}
				if (cnt == 2)return 0;
			}
		}
	}
	if (!cnt)return 0;
	return 1;
}
Position pos_search()
{
	identify(check);
	while (!find(decode())) {
		while (!moving(0))moving(1);
		identify(check);
	}
	return ans;
	/*
	if (first) {
		identify(check);
		while (!find(decode())) {
			while (!moving(0))moving(1);
			identify(check);
		}
		first = false;
		now_y = ans.x;
		now_x = ans.y;
		now_dir = ans.dir;
		return ans;
	}
	else {
		identify(check);
		while (!find2(decode())) {
			while (!moving(0)) {
				moving(1);
				now_dir = (now_dir + 1) % 4;
			}
			identify(check);
		}
		return ans;
	}
	*/
}