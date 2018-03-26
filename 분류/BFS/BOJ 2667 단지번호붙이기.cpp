#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct info {
	int x, y;
};
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int arr[25][25];
bool visited[25][25];
int N, cnt, tot = 0;
queue<info> q;
vector<int> vec;
void BFS()
{
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 0 && r < N && c >= 0 && c < N && arr[r][c] && !visited[r][c])
			{
				cnt++;
				visited[r][c] = true;
				q.push({ r,c });
			}
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (arr[i][j] && !visited[i][j])
			{
				tot++;
				cnt = 1;
				q.push({ i,j });
				visited[i][j] = true;
				BFS();
				vec.push_back(cnt);
			}
		}
	}
	sort(vec.begin(), vec.end());
	printf("%d\n", tot);
	for (int i = 0; i < vec.size(); ++i)printf("%d\n", vec[i]);
}
