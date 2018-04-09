#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

int dr[4] = {0,1,0,-1};
int dc[4] = {-1,0,1,0};
struct info {
	int x, y;
};
queue<info> q;
vector<info> two;
int tmp[3];
info inf[65];
int arr2[9][9];
int arr[9][9];
bool visited[65];
bool visited_arr[9][9];
bool visited_arr2[9][9];
int N, M;
int num = 1;
int mx = 0;
int tot = 0;
int BFS()
{
	int cnt = 0;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		cnt++;
		for (int k = 0; k < 4; ++k)
		{
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 1 && r <= N && c >= 1 && c <= M && !arr2[r][c] && !visited_arr2[r][c])
			{
				arr2[r][c] = 2;
				visited_arr2[r][c] = true;
				q.push({ r,c });
			}
		}
	}
	return cnt;
}
void DFS(int idx, int dep)
{
	if (dep == 3)
	{
		memcpy(arr2, arr, sizeof(arr2));
		memcpy(visited_arr2, visited_arr, sizeof(visited_arr2));
		for (int i = 0; i < 3; ++i)
		{
			arr2[inf[tmp[i]].x][inf[tmp[i]].y] = 1;
			visited_arr2[inf[tmp[i]].x][inf[tmp[i]].y] = true;
		}
		for (int i = 0; i < two.size(); ++i)
		{
			q.push(two[i]);
		}
		int res = BFS();
		res = tot - 3 - res;
		if (mx < res)
			mx = res;
	}
	else
	{
		for (int i = idx + 1; i < num; ++i)
		{
			if (!visited[i])
			{
				visited[i] = true;
				tmp[dep] = i;
				DFS(i, dep + 1);
				visited[i] = false;
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	tot = N * M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0) {
				inf[num].x = i;
				inf[num].y = j;
				num++;
			}
			else if (arr[i][j] == 2) {
				visited_arr[i][j] = true;
				two.push_back({ i, j });
			}
			else {
				tot--;
				visited_arr[i][j] = true;
			}
		}

	DFS(0, 0);
	printf("%d\n", mx);
}
