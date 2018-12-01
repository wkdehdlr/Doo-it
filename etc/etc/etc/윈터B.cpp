#pragma warning(disable : 4996)
#include<cstdio>
#include<string>
using namespace std;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int arr[20][20][4];
int x, y;
string dirs = "LULLLLLLU";

int main()
{
	x = 5, y = 5;
	int len = dirs.size();
	int cnt = 0;
	for (int i = 0; i < len; ++i) {
		int k = 0;
		switch (dirs[i])
		{
		case 'L':k = 0; break;
		case 'D':k = 1; break;
		case 'R':k = 2; break;
		case 'U':k = 3; break;
		}
		int r = x + dr[k];
		int c = y + dc[k];
		if (r >= 0 && r <= 10 && c >= 0 && c <= 10) {
			int z;
			if (k == 0 || k == 2)z = 2 - k;
			else z = 4 - k;
			if (!arr[x][y][k] && !arr[r][c][z]) {
				arr[x][y][k] = arr[r][c][z] = 1;
				cnt++;
			}
			x = r;
			y = c;
		}
	}
	printf("%d\n", cnt);
}