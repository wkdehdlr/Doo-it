#include<cstdio>
#include<cstring>
bool visited[7];
int arr[7];
int main()
{
	int N = 6;
	int mx = 1 << 6;
	for (int i = 0; i < mx; ++i)
	{
		int idx = 0;
		for (int j = 0; j < N; ++j)
		{
			if ( i & (1 << j))
			{
				arr[idx++] = j + 1;
			}
		}
		if (idx == 2)
		{
			for (int k = 0; k < idx; ++k)
			{
				printf("%d ", arr[k]);
			}
			printf("\n");
		}
	}
}