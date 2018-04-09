#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
struct info {
	int rx, ry, bx, by, cnt;
};
queue<info> q;
int N, M;
char arr[10][11];
bool visited[11][11][11][11];

void BFS()
{
	while (!q.empty())
	{
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();
		if (cnt == 10)continue;
		for (int i = 0; i < 4; ++i)
		{
			int rxt = rx, ryt = ry, bxt = bx, byt = by;
			bool done1 = false, done2 = false;
			while (arr[rxt + dr[i]][ryt + dc[i]] != '#')
			{
				if (arr[rxt + dr[i]][ryt + dc[i]] == 'O') { done1 = true; break; }
				rxt += dr[i];
				ryt += dc[i];
			}
			while (arr[bxt + dr[i]][byt + dc[i]] != '#')
			{
				if (arr[bxt + dr[i]][byt + dc[i]] == 'O') { done2 = true; break; }
				bxt += dr[i];
				byt += dc[i];
			}
			if (done1 && done2)continue;
			if (!done1 && done2)continue;
			if (done1 && !done2) { printf("%d\n", cnt + 1); return; }

			if (rxt == bxt && ryt == byt) {//두 공이 겹치는 경우
				switch (i)
				{
				case 0:ry > by ? ryt++ : byt++; break;
				case 1:rx > bx ? bxt-- : rxt--; break;
				case 2:ry > by ? byt-- : ryt--; break;
				case 3:rx > bx ? rxt++ : bxt++; break;
				}
			}
			if (!visited[rxt][ryt][bxt][byt]) {
				visited[rxt][ryt][bxt][byt] = true;
				q.push({ rxt,ryt,bxt,byt,cnt + 1 });
			}
		}
	}
	printf("-1\n");
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%s", arr[i]);

	info inf;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (arr[i][j] == 'B') {
				arr[i][j] = '.';
				inf.bx = i; inf.by = j;
			}
			else if (arr[i][j] == 'R') {
				arr[i][j] = '.';
				inf.rx = i; inf.ry = j;
			}
		}
	}
	visited[inf.rx][inf.ry][inf.bx][inf.by] = true;
	inf.cnt = 0;
	q.push(inf);
	BFS();
}