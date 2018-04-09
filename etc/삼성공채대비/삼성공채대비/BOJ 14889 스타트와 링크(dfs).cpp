#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
int mn = 0x7fffffff;
int N;
int arr[21][21];
int arr1[10];
int arr2[10];
bool visited[21];

void DFS(int idx, int dep)
{
	if (dep == N / 2)
	{
		int idx2 = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (!visited[i])
			{
				arr2[idx2++] = i;
			}
		}
		int num1 = 0, num2 = 0;
		for (int i = 0; i < dep; ++i)
		{
			for (int j = 0; j < dep; ++j)
			{
				num1 += arr[arr1[i]][arr1[j]];
				num2 += arr[arr2[i]][arr2[j]];
			}
		}
		int res = abs(num1 - num2);
		if (mn > res)
			mn = res;
	}
	else
	{
		for (int i = idx + 1; i <= N; ++i)
		{
			if (!visited[i])
			{
				visited[i] = true;
				arr1[dep] = i;
				DFS(i, dep + 1);
				visited[i] = false;
			}
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			scanf("%d", &arr[i][j]);

	for (int i = 1; i <= N / 2; ++i)
	{
		visited[i] = true;
		arr1[0] = i;
		DFS(i, 1);
		visited[i] = false;
	}
	printf("%d\n", mn);
}