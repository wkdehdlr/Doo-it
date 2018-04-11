#include<cstdio>
#include<cstring>
bool visited[5];
int arr[4];
int main()
{
	int N = 4;
	for (int k = 0; k <= 2; ++k)
	{
		int mx = 1 << N;
		for (int i = 0; i < mx / 2; ++i)
		{
			int idx = 0;
			for (int j = 0; j < N; ++j)
			{
				if (i & (1 << j))
				{
					arr[idx++] = j + 1;
				}
			}
			if (idx == k)
			{
				memset(visited, 0, sizeof(visited));
				for (int i = 0; i < idx; ++i)
				{
					visited[arr[i]] = true;
					printf("%d ", arr[i]);
				}
				printf(" // ");
				for (int i = 1; i <= 4; ++i)
				{
					if (!visited[i])
						printf("%d ", i);
				}
				printf("\n");			    
			}
		}
	}
}