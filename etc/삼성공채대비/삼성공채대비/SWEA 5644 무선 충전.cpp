#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int dr[5] = { 0,-1,0,1,0 };
int dc[5] = { 0,0,1,0,-1 };
struct BC {
	int num, power;
};
bool operator<(BC f, BC g) {
	return f.power > g.power;
}
vector<BC> arr[15][15];
int pA[110], pB[110];
int T, M, A, r1, c1, r2, c2;
void set(int r, int c, int num, int len, int power)
{
	for (int x = r - len < 1 ? 1 : r - len; x <= (r + len > 10 ? 10 : r + len); ++x) {
		for (int y = c - len < 1 ? 1 : c - len; y <= (c + len > 10 ? 10 : c + len); ++y) {
			if (abs(r - x) + abs(c - y) <= len)arr[x][y].push_back({ num,power });
		}
	}
}
void input()
{
	for (int i = 1; i <= 10; ++i)for (int j = 1; j <= 10; ++j)if (!arr[i][j].empty())arr[i][j].clear();
	r1 = c1 = 1;
	r2 = c2 = 10;
	scanf("%d %d", &M, &A);
	for (int i = 1; i <= M; ++i)scanf("%d", &pA[i]);
	for (int i = 1; i <= M; ++i)scanf("%d", &pB[i]);
	int num = 1;
	for (int i = 0; i < A; ++i) {
		int x, y, len, power;
		scanf("%d %d %d %d", &x, &y, &len, &power);
		set(y, x, num, len, power); num++;
	}
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			if (arr[i][j].size() >= 2)sort(arr[i][j].begin(), arr[i][j].end());
		}
	}	
}
int calc_mx()
{
	if (arr[r1][c1].empty() && arr[r2][c2].empty())return 0;//둘다 비어있으면
	if (arr[r1][c1].empty() || arr[r2][c2].empty()) {//둘중하나가 비어있을때
		if (arr[r1][c1].empty()) {//A가 비어있을때
			return arr[r2][c2][0].power;
		}
		else {//B가 비어있을때
			return arr[r1][c1][0].power;
		}
	}
	else {//둘다 BC에 연결되어있을때
		int mx = 0;
		for (int i = 0; i < arr[r1][c1].size(); ++i) {
			for (int j = 0; j < arr[r2][c2].size(); ++j) {
				if (arr[r1][c1][i].num == arr[r2][c2][j].num) {
					mx = max(mx, arr[r1][c1][i].power);
				}
				else {
					mx = max(mx, arr[r1][c1][i].power + arr[r2][c2][j].power);
				}
			}
		}
		return mx;
	}
}
void func()
{		
	//0없음 1위 2우 3하 4좌
	int res = 0;
	for (int i = 0; i <= M; ++i) {
		r1 += dr[pA[i]]; c1 += dc[pA[i]];
		r2 += dr[pB[i]]; c2 += dc[pB[i]];
		res += calc_mx();
	}
	printf("%d\n", res);
}		
int main()
{		
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		printf("#%d ", tc + 1);
		input();
		func();
	}
}