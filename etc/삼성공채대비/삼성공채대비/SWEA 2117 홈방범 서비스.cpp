#pragma warning(disable : 4996)
#include<cstdio>

int arr[21][21];
int T, N, M;
int mx = 0;
int cost = 0;
void scan(int i, int j, int k)
{
	int res = 0;
	k--;
	//위쪽
	for (int r = i - k, cnt = 0; r <= i; ++r, ++cnt)
	{
		for (int c = j - cnt; c <= j + cnt; ++c)
		{
			if (r >= 1 && r <= N && c >= 1 && c <= N && arr[r][c])
			{
				res++;
			}
		}
	}

	//아래
	for (int r = i + k, cnt = 0; r > i; --r, ++cnt)
	{
		for (int c = j - cnt; c <= j + cnt; ++c)
		{
			if (r >= 1 && r <= N && c >= 1 && c <= N && arr[r][c])
			{
				res++;
			}
		}
	}
	if (res * M - cost >= 0)
	{
		if (mx < res)
			mx = res;
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		mx = 0;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				scanf("%d", &arr[i][j]);

		for (int k = 1; k <= 21; ++k)
		{
			cost = k * k + (k - 1) * (k - 1);
			for (int i = 1; i <= N; ++i)
			{
				for (int j = 1; j <= N; ++j)
				{
					scan(i, j, k);
				}
			}
		}
		printf("#%d %d\n", tc + 1, mx);
	}
}