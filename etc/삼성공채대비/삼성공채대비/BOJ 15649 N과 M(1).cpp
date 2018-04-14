#pragma warning(disable : 4996)
#include<cstdio>

bool visited[9];
int arr[9];
int N, M;
void DFS(int dep)
{
	if (dep == M + 1)
	{
		for (int i = 1; i <= M; ++i)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			if (!visited[i])
			{
				visited[i] = true;
				arr[dep] = i;
				DFS(dep + 1);
				visited[i] = false;
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	DFS(1);
}