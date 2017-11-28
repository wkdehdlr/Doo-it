#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

char arr[20][20];
char en;
int R, C, T;
int memory;

int main()
{
	scanf("%d", &T);
	scanf("%c", &en);
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d %d", &R, &C);
		scanf("%c", &en);
		memory = 0;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				scanf("%c", &arr[i][j]);
			}
			scanf("%c", &en);
		}
		DFS(1, 1, 2);
		printf("\n");
	}
}
void DFS(int i, int j, int dir)
{
	if (arr[i][j] == '@')
	{
		printf("YES\n");
	}
	else
	{
		if (arr[i][j] >= '0' && arr[i][j] <= '9')
		{
			memory = arr[i][j] - '0';
			DFS((i + dr[dir] + R) % R, (j + dc[dir] + C) % C, dir);
		}
		else 
		{
			switch (arr[i][j])
			{
			case '<':DFS((i + dr[0] + R) % R, (j + dc[0] + C) % C, 0); break;
			case '>':DFS((i + dr[2] + R) % R, (j + dc[2] + C) % C, 2); break;
			case '^':DFS((i + dr[3] + R) % R, (j + dc[3] + C) % C, 3); break;
			case 'v':DFS((i + dr[1] + R) % R, (j + dc[1] + C) % C, 1); break;
			case '+':memory = (memory + 1 + 16) % 16; DFS((i + dr[dir] + R) % R, (j + dc[dir] + C) % C, dir); break;
			case '-':memory = (memory - 1 + 16) % 16; DFS((i + dr[dir] + R) % R, (j + dc[dir] + C) % C, dir); break;
			case '.':DFS((i + dr[dir] + R) % R, (j + dc[dir] + C) % C, dir); break;
			case '|':if(!memory)DFS((i + dr[1] + R) % R, (j + dc[1] + C) % C, 1);else DFS((i + dr[3] + R) % R, (j + dc[3] + C) % C, 3); break;
			case '_':if(!memory)DFS((i + dr[2] + R) % R, (j + dc[2] + C) % C, 2); else DFS((i + dr[0] + R) % R, (j + dc[0] + C) % C, 0); break;
			case '?':break;
			}
		}
	}
}