#pragma warning(disable : 4996)
#include<cstdio>
int dr[8] = { 0,1,1,1,0,-1,-1,-1 };
int dc[8] = { -1,-1,0,1,1,1,0,-1 };
int arr[20][20];
void go(int x, int y, int k,int team)
{
	int r = x + dr[k];
	int c = y + dc[k];
	if (r >= 1 && r <= 19 && c >= 1 && c <= 19 && arr[r][c] == team) {
			
	}
}
void func()
{
	for (int i = 1; i <= 19; ++i) {
		for (int j = 1; j <= 19; ++j) {
			if (arr[i][j] == 1 || arr[i][j] == 2) {
				for (int k = 0; k < 8; ++k) {
					int r = i + dr[k];
					int c = j + dc[k];
					if (r >= 1 && r <= 19 && c >= 1 && c <= 19 && arr[i][j] == arr[r][c]) {
						go(r, c, k,arr[i][j]);
					}
				}
			}
		}
	}

}
int main()
{
	for (int i = 1; i <= 19; ++i)
		for (int j = 1; j <= 19; ++j)
			scanf("%d", &arr[i][j]);
	func();
}