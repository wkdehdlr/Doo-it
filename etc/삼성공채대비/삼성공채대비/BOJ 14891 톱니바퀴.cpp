#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
struct info {
	int idx, dir;
};
int dr[2] = { -1,1 };
queue<info> q;
queue<info> res;
bool visited[4];
int arr[4][8];
int K;
void rot()
{
	while (!res.empty())
	{
		int idx = res.front().idx;
		int dir = res.front().dir;
		res.pop();
		
		if (dir == 1) {
			rotate(arr[idx], arr[idx] + 7, arr[idx] + 8);
		}
		else {
			rotate(arr[idx], arr[idx] + 1, arr[idx] + 8);
		}
	}
}
void BFS()
{
	while (!q.empty())
	{
		int idx = q.front().idx;
		int dir = q.front().dir;
		q.pop();

		for (int k = 0; k < 2; ++k)
		{
			int id = idx + dr[k];
			if (id >= 0 && id < 4 && !visited[id])
			{
				if (id < idx) {
					if (arr[idx][6] != arr[id][2]) {
						visited[id] = true;
						q.push({ id,dir == 1 ? -1 : 1 });
						res.push({ id,dir == 1 ? -1 : 1 });
					}
				}
				else {
					if (arr[idx][2] != arr[id][6]) {
						visited[id] = true;
						q.push({ id,dir == 1 ? -1 : 1 });
						res.push({ id,dir == 1 ? -1 : 1 });
					}
				}
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 8; ++j)
			scanf("%1d", &arr[i][j]);
	
	scanf("%d", &K);
	for (int tc = 0; tc < K; ++tc)
	{
		int idx, dir;
		scanf("%d %d", &idx, &dir);
		memset(visited, 0, sizeof(visited));
		visited[idx - 1] = true;
		q.push({ idx - 1,dir });
		res.push({ idx - 1,dir });
		BFS();
		rot();
	}
	int cnt = 1;
	int tot = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (arr[i][0])tot += cnt;
		cnt *= 2;
	}
	printf("%d\n", tot);
}