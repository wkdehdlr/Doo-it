#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

bool qt[20][20];
bool check[20][20][16][4];
char arr[20][20];
char en;
int R, C, T;
int memory;
bool flag;

void DFS(int, int, int);
int main()
{
	scanf("%d", &T);
	scanf("%c", &en);
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d %d", &R, &C);
		scanf("%c", &en);
		memory = 0;
		flag = false;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				scanf("%c", &arr[i][j]);
			}
			scanf("%c", &en); //scanf("%c", &en);
		}
		DFS(0, 0, 2);
		printf("#%d ", tc + 1);
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
		memset(check, false, sizeof(bool) * 20 * 20 * 16 * 4);
		memset(qt, false, sizeof(bool) * 20 * 20);
	}
}
void DFS(int i, int j, int dir)
{
	if (arr[i][j] == '@')
	{
		flag = true;
	}
	else
	{
		if (check[i][j][memory][dir])
			return;
		else
			check[i][j][memory][dir] = true;

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
			case '?':
				qt[i][j] = true;
				for (int k = 0; k < 4; ++k)
				{
					int x = i + dr[k];
					int y = j + dc[k];
					if (x >= 0 && x < R && y >= 0 && y < C && !check[x][y][memory][k])
					{
						if (arr[x][y] == '?')
						{
							if (!qt[x][y])
							{
								DFS(x, y, k);
							}
						}
						else
						{
							DFS(x, y, k);
						}
					}
				}
				break;
			}
		}
	}
}