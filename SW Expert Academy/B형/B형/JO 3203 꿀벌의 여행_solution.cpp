
COORD start, mybee[MAXBEE], pt[MAXBEE], bs, be, target[MAXBEE];

int NN, ans;
int order[MAXBEE], num[MAXBEE], chk[MAXBEE];
int map[100][100], dir[7];
const int yy[5] = { 0,0,1,0,-1 };
const int xx[5] = { 0,1,0,-1,0 };

int moveBee(int dir[MAXBEE]);
int Min(int x, int y) { return x < y ? x : y; }
int Max(int x, int y) { return x > y ? x : y; }
int Abs(int x) { return x < 0 ? -x : x; }

void init(int n, COORD bee[MAXBEE])
{
	NN = n;
	bs.y = bs.x = 100;
	be.y = be.x = 0;
	for (int i = 0; i < NN; ++i) {
		mybee[i].y = bee[i].y;
		mybee[i].x = bee[i].x;
		bs.x = Min(bs.x, bee[i].x);
		be.x = Max(be.x, bee[i].x);
		bs.y = Min(bs.y, bee[i].y);
		be.y = Max(be.y, bee[i].y);
	}
}
/*
int move(int k)
{
	int i, j, flag = 0, ny, nx;
	for (i = 0; i < N; i++) {
		dir[i] = 0;
		for (j = 1; j <= 4; j++) {
			ny = mybee[i].y + yy[j]; nx = mybee[i].x + xx[j];
			if (Abs(target[i].y - mybee[i].y) < Abs(target[i].y - ny))continue;
			if (Abs(target[i].x - mybee[i].x) < Abs(target[i].x - nx))continue;
			if (map[ny][nx] == k)continue;
			map[ny][nx] = k;
			dir[i] = j;
			mybee[i].y = ny; mybee[i].x = nx;
			flag = 1;
			break;
		}
	}
	return flag;
}*/
int move(int j)
{
	int flag = 0;
	for (int i = 0; i < NN; ++i) {
		dir[i] = 0;
		for (int k = 1; k < 5; ++k) {
			int y = mybee[i].y + yy[k];
			int x = mybee[i].x + xx[k];
			if (y < 0 || y >= 100)continue;
			if (x < 0 || x >= 100)continue;
			if (Abs(mybee[i].y - target[i].y) < Abs(y - target[i].y))continue;
			if (Abs(mybee[i].x - target[i].x) < Abs(x - target[i].x))continue;
			if (map[y][x] == j)continue;
			dir[i] = k;
			mybee[i].y = y;
			mybee[i].x = x;
			map[y][x] = j;
			flag = 1;
			break;
		}
	}
	return flag;
}
void dfs(int sy, int sx, int n, int maxd)
{
	if (maxd >= ans)return;
	int i, k;
	if (n >= NN) {
		ans = maxd; start.y = sy; start.x = sx;
		for (i = 0; i < NN; i++)order[i] = num[i];
	}
	for (i = 0; i < NN; i++) {
		if (chk[i]) continue;
		chk[i] = 1;
		num[n] = i;
		k = Abs(pt[i].y + sy - mybee[n].y)
			+ Abs(pt[i].x + sx - mybee[n].x);
		dfs(sy, sx, n + 1, Max(maxd, k));
		chk[i] = 0;
	}
}
void setting(int h, int w)
{
	int i, j, k, sy, sx, ey, ex;
	//sy = (bs.y + (be.y - h)) / 2, sx = (bs.x + (be.x - w)) / 2;
	//if (sy < 0)sy = 0; if (sy > 100 - h)sy = 100 - h;
	//if (sx < 0)sx = 0; if (sx > 100 - w)sx = 100 - w;
	//for (k = 0; k < NN; k++)chk[k] = 0;
	//dfs(sy, sx, 0, 0);

	sy = Max(0, bs.y - h + 1); sx = Max(0, bs.x - w + 1);
	ey = Min(MAXSIZE - h, be.y); ex = Min(MAXSIZE - w, be.x);

	for (i = sy; i <= ey; i++)for (j = sx; j <= ex; j++) {
		for (k = 0; k < NN; k++)chk[k] = 0;
		dfs(i, j, 0, 0);
	}
}
COORD make_pattern(int height, int width, int pattern[MAXSIZE][MAXSIZE])
{
	int i, j, k = 0;
	for (i = 0; i < 100; i++)for (j = 0; j < 100; j++)map[i][j] = 0;
	for (i = 0; i < height; i++)for (j = 0; j < width; j++) {
		if (pattern[i][j]) {
			pt[k].y = i; pt[k].x = j; k++;
		}
	}
	ans = 10000;
	setting(height, width);
	for (i = 0; i < NN; i++) {
		target[i].y = pt[order[i]].y + start.y;
			target[i].x = pt[order[i]].x + start.x;
	}

	for (k = 1; move(k); k++)moveBee(dir);

	bs = be = start;
	be.y += height - 1, be.x += width - 1;
	return start;
}
