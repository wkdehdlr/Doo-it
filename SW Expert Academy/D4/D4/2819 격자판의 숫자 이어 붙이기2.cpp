#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<string>
#include<map>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

struct info {
	int x;
	int y;
	int depth;
	string str;
};

queue<info> q;
int arr[4][4];
map<string, bool> ma[10];
int cnt = 0;
int T;

void BFS(int);
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{	
		cnt = 0;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				q.push({ i,j,0,to_string(arr[i][j]) });
				BFS(tc);
			}
		}
		printf("#%d %d\n", tc+1,cnt);
		//ma[tc].clear();
	}
	return 0;
}
void BFS(int tc)
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int depth = q.front().depth;
		string str = q.front().str;
		q.pop();

 		if (depth == 6)
		{
			if (ma[tc].find(str) == ma[tc].end())
			{
				ma[tc][str] = true;
				cnt++;
			}
			continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			int r = x + dr[i];
			int c = y + dc[i];
			if (r >= 0 && r < 4 && c >= 0 && c < 4)
			{
				q.push({ r,c,depth + 1,str + to_string(arr[r][c]) });
			}
		}
	}
}