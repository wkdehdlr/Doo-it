#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<cmath>

bool visited[21];
int ary[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
int arr1[10];
int arr2[10];
int N;
int arr[21][21];
int mn = 0x7fffffff;
void func()
{
	int n = N;
	int c = N / 2;

	int idx = 0;
	int mx = 1 << n;
	for (int i = 0; i < mx / 2; ++i)
	{
		memset(visited, 0, sizeof(visited));
		idx = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				arr1[idx++] = ary[j];
				visited[ary[j]] = true;
			}
		}
		if (idx == c)
		{
			int idx2 = 0;
			for (int k = 1; k <= N; ++k)
			{
				if (!visited[k])
				{
					arr2[idx2++] = k;
				}
			}
			//arr1, arr2
			int num1 = 0, num2 = 0, res = 0;
			for (int k = 0; k < c; ++k)
			{
				for (int t = 0; t < c; ++t)
				{
					num1 += arr[arr1[k]][arr1[t]];
					num2 += arr[arr2[k]][arr2[t]];
				}
			}
			res = abs(num1 - num2);
			if (res < mn)
				mn = res;
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			scanf("%d", &arr[i][j]);

	func();
	printf("%d\n", mn);
}