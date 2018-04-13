#include<cstdio>
#include<cstring>
bool visited[7];
int arr[7];
int main()
{
	int N = 3;
	int mx = 1 << N;
	for (int k = 0; k <= 3; ++k)
	{
		for (int i = 0; i < mx; ++i)
		{
			memset(visited, 0, sizeof(visited));
			int idx = 0;
			for (int j = 0; j < N; ++j)
			{
				if (i & (1 << j))
				{
					visited[j + 1] = true;
					idx++;
				}
			}
			if (idx == k)
			{
				for (int i = 1; i <= N; ++i)
				{
					if (visited[i])printf("%d ", i);
				}
				printf(" // ");
				for (int i = 1; i <= N; ++i)
				{
					if (!visited[i])printf("%d ", i);
				}
				printf("\n");
			}
		}
	}
}