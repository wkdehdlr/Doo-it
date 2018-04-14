#include<cstdio>
#include<cstring>

bool visited[11];
int arr[6];
int main()
{
	int N = 6;
	int mx = 1 << N;
	for (int t = 0; t <= 3; ++t)
	{
		for (int i = 0; i < mx / 2; ++i)
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
			if (idx == t)
			{
				for (int k = 1; k <= 6; ++k)
				{
					if (visited[k])printf("%d ", k);
				}
				printf("  //  ");
				for (int k = 1; k <= 6; ++k)
				{
					if (!visited[k])printf("%d ", k);
				}
				printf("\n");
			}
		}
	}
}