#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
queue<info> q;
int N, K, L;
int arr[101][101];
int dir[10001];
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y] = 3;
	}

	scanf("%d", &L);
	for (int i = 0; i < L; ++i)
	{
		int idx;
		char str[2];
		scanf("%d %s", &idx, str);
		if (str[0] == 'D')dir[idx] = 1;
		else dir[idx] = 2;
	}
	int x = 1, y = 1, di = 2, cnt = 0;
	arr[x][y] = 2;
	q.push({ x,y });
	while (1)
	{
		if (dir[cnt] == 1) {
			di = (di + 3) % 4;
		}
		else if (dir[cnt] == 2) {
			di = (di + 1) % 4;
		}
		int r = x + dr[di];
		int c = y + dc[di];
		if (r >= 1 && r <= N && c >= 1 && c <= N)
		{
			if (arr[r][c] == 2)break;//³» ¸öÀ» ¸¸³µÀ»¶§
			else if (arr[r][c] == 0) {//±×³É ºóÄ­ÀÏ¶§
				arr[r][c] = 2;
				arr[q.front().x][q.front().y] = 0;
				q.pop();
				q.push({ r,c });
				x = r; y = c;
			}
			else if (arr[r][c] == 3) {//»ç°ú¸¦ ¸¸³µÀ»¶§
				arr[r][c] = 2;
				q.push({ r,c });
				x = r; y = c;
			}
		}
		else break;//º®À» ¸¸³µÀ»¶§
		cnt++;
	}
	printf("%d\n", cnt + 1);
}