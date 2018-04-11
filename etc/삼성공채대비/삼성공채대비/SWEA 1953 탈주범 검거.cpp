#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

struct info {
	int x, y, dir;
};
queue<info> q;
int arr[50][50];
int visited[50][50];
int N, M, R, C, L, T, tot;
void func1(int x, int y)
{
	//위
	if (x - 1 >= 0 && !visited[x - 1][y] && (arr[x - 1][y] == 1 || arr[x - 1][y] == 2 || arr[x - 1][y] == 5 || arr[x - 1][y] == 6))
	{
		visited[x - 1][y] = visited[x][y] + 1;
		q.push({ x - 1,y,arr[x - 1][y] });
	}

	//아래
	if (x + 1 < N && !visited[x + 1][y] && (arr[x + 1][y] == 1 || arr[x + 1][y] == 2 || arr[x + 1][y] == 4 || arr[x + 1][y] == 7))
	{
		visited[x + 1][y] = visited[x][y] + 1;
		q.push({ x + 1,y,arr[x + 1][y] });
	}

	//왼쪽
	if (y - 1 >= 0 && !visited[x][y - 1] && (arr[x][y - 1] == 1 || arr[x][y - 1] == 3 || arr[x][y - 1] == 4 || arr[x][y - 1] == 5))
	{
		visited[x][y - 1] = visited[x][y] + 1;
		q.push({ x,y - 1,arr[x][y - 1] });
	}

	//오른쪽
	if (y + 1 < M && !visited[x][y + 1] && (arr[x][y + 1] == 1 || arr[x][y + 1] == 3 || arr[x][y + 1] == 6 || arr[x][y + 1] == 7))
	{
		visited[x][y + 1] = visited[x][y] + 1;
		q.push({ x,y + 1,arr[x][y + 1] });
	}
}
void func2(int x, int y)
{
	//위
	if (x - 1 >= 0 && !visited[x - 1][y] && (arr[x - 1][y] == 1 || arr[x - 1][y] == 2 || arr[x - 1][y] == 5 || arr[x - 1][y] == 6))
	{
		visited[x - 1][y] = visited[x][y] + 1;
		q.push({ x - 1,y,arr[x - 1][y] });
	}

	//아래
	if (x + 1 < N && !visited[x + 1][y] && (arr[x + 1][y] == 1 || arr[x + 1][y] == 2 || arr[x + 1][y] == 4 || arr[x + 1][y] == 7))
	{
		visited[x + 1][y] = visited[x][y] + 1;
		q.push({ x + 1,y,arr[x + 1][y] });
	}
}
void func3(int x, int y)
{
	//왼쪽
	if (y - 1 >= 0 && !visited[x][y - 1] && (arr[x][y - 1] == 1 || arr[x][y - 1] == 3 || arr[x][y - 1] == 4 || arr[x][y - 1] == 5))
	{
		visited[x][y - 1] = visited[x][y] + 1;
		q.push({ x,y - 1,arr[x][y - 1] });
	}

	//오른쪽
	if (y + 1 < M && !visited[x][y + 1] && (arr[x][y + 1] == 1 || arr[x][y + 1] == 3 || arr[x][y + 1] == 6 || arr[x][y + 1] == 7))
	{
		visited[x][y + 1] = visited[x][y] + 1;
		q.push({ x,y + 1,arr[x][y + 1] });
	}
}
void func4(int x, int y)
{
	//위
	if (x - 1 >= 0 && !visited[x - 1][y] && (arr[x - 1][y] == 1 || arr[x - 1][y] == 2 || arr[x - 1][y] == 5 || arr[x - 1][y] == 6))
	{
		visited[x - 1][y] = visited[x][y] + 1;
		q.push({ x - 1,y,arr[x - 1][y] });
	}

	//오른쪽
	if (y + 1 < M && !visited[x][y + 1] && (arr[x][y + 1] == 1 || arr[x][y + 1] == 3 || arr[x][y + 1] == 6 || arr[x][y + 1] == 7))
	{
		visited[x][y + 1] = visited[x][y] + 1;
		q.push({ x,y + 1,arr[x][y + 1] });
	}
}
void func5(int x, int y)
{
	//아래
	if (x + 1 < N && !visited[x + 1][y] && (arr[x + 1][y] == 1 || arr[x + 1][y] == 2 || arr[x + 1][y] == 4 || arr[x + 1][y] == 7))
	{
		visited[x + 1][y] = visited[x][y] + 1;
		q.push({ x + 1,y,arr[x + 1][y] });
	}

	//오른쪽
	if (y + 1 < M && !visited[x][y + 1] && (arr[x][y + 1] == 1 || arr[x][y + 1] == 3 || arr[x][y + 1] == 6 || arr[x][y + 1] == 7))
	{
		visited[x][y + 1] = visited[x][y] + 1;
		q.push({ x,y + 1,arr[x][y + 1] });
	}
}
void func6(int x, int y)
{
	//왼쪽
	if (y - 1 >= 0 && !visited[x][y - 1] && (arr[x][y - 1] == 1 || arr[x][y - 1] == 3 || arr[x][y - 1] == 4 || arr[x][y - 1] == 5))
	{
		visited[x][y - 1] = visited[x][y] + 1;
		q.push({ x,y - 1,arr[x][y - 1] });
	}

	//아래
	if (x + 1 < N && !visited[x + 1][y] && (arr[x + 1][y] == 1 || arr[x + 1][y] == 2 || arr[x + 1][y] == 4 || arr[x + 1][y] == 7))
	{
		visited[x + 1][y] = visited[x][y] + 1;
		q.push({ x + 1,y,arr[x + 1][y] });
	}
}
void func7(int x, int y)
{
	//위
	if (x - 1 >= 0 && !visited[x - 1][y] && (arr[x - 1][y] == 1 || arr[x - 1][y] == 2 || arr[x - 1][y] == 5 || arr[x - 1][y] == 6))
	{
		visited[x - 1][y] = visited[x][y] + 1;
		q.push({ x - 1,y,arr[x - 1][y] });
	}

	//왼쪽
	if (y - 1 >= 0 && !visited[x][y - 1] && (arr[x][y - 1] == 1 || arr[x][y - 1] == 3 || arr[x][y - 1] == 4 || arr[x][y - 1] == 5))
	{
		visited[x][y - 1] = visited[x][y] + 1;
		q.push({ x,y - 1,arr[x][y - 1] });
	}
}
void BFS()
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		tot++;
		q.pop();
		if (visited[x][y] == L)continue;
		switch (dir)
		{
		case 1:func1(x, y); break;
		case 2:func2(x, y); break;
		case 3:func3(x, y); break;
		case 4:func4(x, y); break;
		case 5:func5(x, y); break;
		case 6:func6(x, y); break;
		case 7:func7(x, y); break;
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		memset(visited, 0, sizeof(visited));
		tot = 0;
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				scanf("%d", &arr[i][j]);

		visited[R][C] = 1;
		q.push({ R,C,arr[R][C] });
		BFS();
		printf("#%d %d\n", tc + 1, tot);
	}
}