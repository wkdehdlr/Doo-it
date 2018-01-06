#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int maxN = 0;
int visited[10001];
int arr[10001][10001];
int N, M;
int endd;

void DFS(int start, int w)
{
	if (start == endd)
	{
		if (maxN < w)
			maxN = w;	
	}
	else
	{
		visited[start] = w;
		for (int i = 1; i <= N; ++i)
		{
			if (arr[start][i] && !visited[i])
			{
				if(!w)
					DFS(i, arr[start][i]);
				else
					if(w > arr[start][i])
						DFS(i, arr[start][i]);
					else
						DFS(i, w);
			}
		}
		visited[start] = 0;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		int sum1, sum2, w;
		scanf("%d %d %d", &sum1, &sum2, &w);
		if (arr[sum1][sum2] < w)
		{
			arr[sum1][sum2] = w;
			arr[sum2][sum1] = w;
		}
	}
	int start;
	scanf("%d %d", &start, &endd);
	DFS(start,0);
	printf("%d\n", maxN);
}