#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;


int dr[4] = {0,1,0,-1};
int dc[4] = {-1,0,1,0};
struct jum {
	int x;
	int y;
	int cnt;
};
struct room {
	int room_num;
	int cnt;
};
bool operator<(room t, room u) {
	if (t.cnt == u.cnt)
	{
		return t.room_num > u.room_num;
	}
	else
	{
		return t.cnt < u.cnt;
	}
}
queue<jum> q;
priority_queue<room> pq;
int visited[1001][1001];
int arr[1001][1001];
int T, N, maxN, cnt;

void BFS();
int main()
{
	priority_queue<room> pq_temp;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		pq = pq_temp;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (visited[i][j] == false)
				{
					q.push({ i,j,1 });
					BFS();
					if (maxN != 1)
						pq.push({ arr[i][j],maxN });
				}
			}
		}
		printf("#%d %d %d\n", tc + 1, pq.top().room_num, pq.top().cnt);
	}
}
void BFS()
{
	maxN = 1;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		cnt = q.front().cnt;
		if (maxN < cnt)
			maxN = cnt;

		int data = arr[x][y];
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 1 && r <= N && c >= 1 && c <= N && data + 1 == arr[r][c] && visited[r][c] == false)
			{
				visited[r][c] = true;
				q.push({ r,c,cnt + 1 });
			}
		}
	}
}