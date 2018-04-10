#include<cstdio>

int arr[3];
int main()
{
	int N = 6;
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
		if (idx == 3)
		{
			printf("%d %d %d\n", arr[0], arr[1], arr[2]);
		}
	}
}