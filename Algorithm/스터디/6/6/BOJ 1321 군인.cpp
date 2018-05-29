#pragma warning(disable : 4996)
#include<cstdio>

int arr[1 << 20];
int N, M;
int idx = 1;
void update(int i, int val)
{
	i += idx;
	arr[i] += val;
	while (i > 1)
	{
		i /= 2;
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}
}
int sum(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	if (R < nodeL || nodeR < L)return 0;
	if (L <= nodeL && nodeR <= R)return arr[nodeNum];

	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}
int main()
{
	scanf("%d", &N);
	while (idx < N)idx *= 2;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		update(i, tmp);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int a;
		scanf("%d", &a);
		if (a == 1)
		{
			int num, x;
			scanf("%d %d", &num, &x);
			update(num - 1, x);
		}
		else
		{
			int num;
			scanf("%d", &num);
			int left = 0, right = idx - 1;
			int mid = 0;
			while (left <= right)
			{
				mid = (left + right) / 2;
				int res = sum(0, mid, 1, 0, idx - 1);
				if (res >= num)
					right = mid - 1;
				else if (res < num)
					left = mid + 1;
			}
			printf("%d\n", left + 1);
		}
	}
}