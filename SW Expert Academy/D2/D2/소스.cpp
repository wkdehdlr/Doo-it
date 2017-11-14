#include <stdio.h>

int data[] = { 1,2,3,4 };
int data2[2];

void powerset(int n)
{
	int i, j;
	int max = 1 << n;
	for (i = 0; i<max; i++) {
		int cnt = 0;
		for (j = 0; j<n; j++) {
			if (i & (1 << j))
			{
				data2[cnt] = data[j];
				cnt++;
			}
		}
		if (cnt == 2)
		{
			printf("{%d %d}\n", data2[0], data2[1]);
		}
	}
}

int main()
{
	powerset(sizeof(data) / sizeof(int));
	return 0;
}

void nck(int n, int k)
{
	if (k == 0)
	{

	}
	else if (n < k)
	{
		return;
	}
	else
	{
		new_data[k - 1] = data[n - 1];
		nck(n - 1, k - 1);
		nck(n - 1, k);
	}
}

int max = 1 << N;
for (int i = 0; i < max; ++i)
{
	for (int j = 0; j < N; ++j)
	{
		if (i & (1 << j))
		{

		}
	}
}