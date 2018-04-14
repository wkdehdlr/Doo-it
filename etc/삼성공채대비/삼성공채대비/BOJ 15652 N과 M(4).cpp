#pragma warning(disable : 4996)
#include<cstdio>

int arr[9];
int N, M;
void DFS(int idx, int dep)
{
	if (dep == M + 1)
	{
		for (int i = 1; i <= M; ++i)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for (int i = idx; i <= N; ++i)
		{
			arr[dep] = i;
			DFS(i, dep + 1);
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	DFS(1, 1);
}