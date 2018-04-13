#include<cstdio>

int arr[11];
bool visited[11];
void DFS(int idx, int dep)
{
	if (dep == 3)
	{
		for (int i = 1; i <= 3; ++i)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for (int i = idx; i <= 3; ++i)
		{
			if (visited[i]) {
				arr[i] = 1;
				DFS(idx + 1, dep + 1);
				arr[i] = 2;
				DFS(idx + 1, dep + 1);
				break;
			}
			else {
				arr[i] = 0;
				DFS(idx + 1, dep + 1);
				break;
			}
		}
	}
}
void func(int dep, int k)
{
	if (k == 0)
	{
		DFS(1, 0);
	}
	else if (dep > 3)return;
	else
	{
		visited[dep] = 1;
		func(dep + 1, k - 1);
		visited[dep] = 0;
		func(dep + 1, k);
	}
}
int main()
{
	for (int k = 0; k <= 3; ++k)
	{
		func(1, k);
	}
}
