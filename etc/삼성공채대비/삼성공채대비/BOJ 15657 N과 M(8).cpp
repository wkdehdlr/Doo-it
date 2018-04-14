#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

bool visited[9];
int tmp[9];
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
			arr[dep] = tmp[i];
			DFS(i, dep + 1);
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &tmp[i]);
	sort(tmp + 1, tmp + N + 1);
	DFS(1, 1);
}