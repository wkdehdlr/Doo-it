#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

struct sh {
	int dist;
	int i, j;
};
bool operator<(sh f, sh g)
{
	if (f.dist == g.dist) {
		if (f.i == g.i) {
			return f.j > g.j;
		}
		return f.i > g.i;
	}
	return f.dist > g.dist;
}

int N, x, y, s, n, time;
int arr[20][20];
int visited[20][20];
queue<sh> q;
priority_queue<sh> pq;
void input()
{
	n = 0;
	time = 0;
	s = 2;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 9) {
				x = i; y = j;
			}
		}
	}
}
int func()
{
	memset(visited, 0, sizeof(visited));
	q.push({ 0,x,y });
	visited[x][y] = 1;
	while(!q.empty())
	{
		int i = q.front().i;
		int j = q.front().j;
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int r = i + dr[k];
			int c = j + dc[k];
			if (r >= 0 && r < N && c >= 0 && c < N && !visited[r][c] && arr[r][c] <= s) {
				if (arr[r][c] > 0 && arr[r][c] < s)pq.push({ visited[i][j],r,c });
				else {
					visited[r][c] = visited[i][j] + 1;
					q.push({ 0,r,c });
				}
			}
		}
	}
	if (pq.empty())return 0;
	else {
		int i = pq.top().i;
		int j = pq.top().j;
		int dist = pq.top().dist;
		time += dist;
		arr[x][y] = 0;
		arr[i][j] = 9;
		x = i; y = j;
		n++;
		if (n == s) {
			n = 0; s++;
		}
		while (!pq.empty())pq.pop();
		return 1;
	}
}
int main()
{
	input();
	while (func());
	printf("%d\n", time);
}