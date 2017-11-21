#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;


int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
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
bool visited[1001][1001];
int arr[1001][1001];
int T, N, maxN, cnt, minN;

void DFS(int, int, int,int);
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
				visited[i][j] = false;
			}
		}
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				minN = 0x7fffffff;
				cnt = 1;
				DFS(i, j, 0, 3);

				if (minN != 0x7fffffff)
				{
					pq.push({ minN,cnt });
					continue;
				}
				if (cnt != 1)
					pq.push({ arr[i][j],cnt });
			}
		}
		printf("#%d %d %d\n", tc + 1, pq.top().room_num, pq.top().cnt);
	}
}
void DFS(int i, int j,int flag,int plus_minus)
{
	if (visited[i][j] == true)
	{
		return;
	}
	else
	{
		visited[i][j] = true;
		int data = arr[i][j];
		for (int k = 0; k < 4; ++k)
		{
			int r = i + dr[k];
			int c = j + dc[k];
			if (r >= 1 && r <= N && c >= 1 && c <= N && visited[r][c] == false)
			{
				if (data + 1 == arr[r][c])
				{
					cnt++;
					DFS(r, c, 1, 1);
				}
				else if (data - 1 == arr[r][c])
				{
					cnt++;
					DFS(r, c, 1, -1);
				}
			}
		}

		if (flag == 0)
			visited[i][j] = false;

		if (plus_minus == -1)
			if (arr[i][j] < minN)
				minN = arr[i][j];
	}
}