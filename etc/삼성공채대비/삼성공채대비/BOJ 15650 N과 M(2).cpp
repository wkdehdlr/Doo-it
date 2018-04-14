#pragma warning(disable : 4996)
#include<cstdio>

bool visited[9];
int N, M;
void DFS(int idx, int dep)
{
	if (dep == M + 1)
	{
		for (int i = 1; i <= N; ++i)
			if (visited[i])printf("%d ", i);
		printf("\n");
	}
	else
	{
		for (int i = idx; i <= N; ++i)
		{
			visited[i] = true;
			DFS(i + 1, dep + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	DFS(1, 1);
}