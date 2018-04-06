#pragma warning(disable : 4996)
#include<cstdio>

int arr[501][501];
int N, M;
int mx = 0;
void func1(int i, int j)
{
	if (j + 3 <= M)
	{
		int res = 0;
		for (int idx = j; idx <= j + 3; ++idx)
		{
			res += arr[i][idx];
		}
		if (res > mx)
			mx = res;
	}

	if (i + 3 <= N)
	{
		int res = 0;
		for (int idx = i; idx <= i + 3; ++idx)
		{
			res += arr[idx][j];
		}
		if (res > mx)
			mx = res;
	}
}
void func2(int i, int j)
{
	if (i + 1 <= N && j + 1 <= M)
	{
		int res = 0;
		for (int r = i; r <= i + 1; ++r)
		{
			for (int c = j; c <= j + 1; ++c)
			{
				res += arr[r][c];
			}
		}
		if (res > mx)
			mx = res;
	}
}
void func3(int i, int j)
{
	if (i + 2 <= N && j + 1 <= M)
	{
		int res = 0;
		int idx = i;
		for (; idx <= i + 2; ++idx)
		{
			res += arr[idx][j];
		}
		res += arr[idx - 1][j + 1];
		if (res > mx)
			mx = res;

		res = 0;
		idx = i;
		for (; idx <= i + 2; ++idx)
		{
			res += arr[idx][j + 1];
		}
		res += arr[i][j];
		if (res > mx)
			mx = res;

		res = 0;
		idx = i;
		for (; idx <= i + 2; ++idx)
		{
			res += arr[idx][j + 1];
		}
		res += arr[idx - 1][j];
		if (res > mx)
			mx = res;

		res = 0;
		idx = i;
		for (; idx <= i + 2; ++idx)
		{
			res += arr[idx][j];
		}
		res += arr[i][j + 1];
		if (res > mx)
			mx = res;
	}

	if (i + 1 <= N && j + 2 <= M)
	{
		int res = 0;
		int idx = j;
		for (; idx <= j + 2; ++idx)
		{
			res += arr[i][idx];
		}
		res += arr[i + 1][j];
		if (res > mx)
			mx = res;

		res = 0;
		idx = j;
		for (; idx <= j + 2; ++idx)
		{
			res += arr[i][idx];
		}
		res += arr[i + 1][idx - 1];
		if (res > mx)
			mx = res;
	}

	if (i + 1 <= N && j + 2 <= M)
	{
		int res = 0;
		int idx = j;
		for (; idx <= j + 2; ++idx)
		{
			res += arr[i + 1][idx];
		}
		res += arr[i][idx - 1];
		if (res > mx)
			mx = res;

		res = 0;
		idx = j;
		for (; idx <= j + 2; ++idx)
		{
			res += arr[i + 1][idx];
		}
		res += arr[i][j];
		if (res > mx)
			mx = res;
	}
}
void func4(int i, int j)
{
	if (i + 2 <= N && j + 1 <= M)
	{
		int res = 0;
		res += (arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1]);
		if (res > mx)
			mx = res;

		res = 0;
		res += (arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j]);
		if (res > mx)
			mx = res;
	}

	if (i + 1 <= N && j + 2 <= M)
	{
		int res = 0;
		res += (arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 1][j]);
		if (res > mx)
			mx = res;

		res = 0;
		res += (arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
		if (res > mx)
			mx = res;
	}
}
void func5(int i, int j)
{
	if (i + 1 <= N && j + 2 <= M)
	{
		int res = 0;
		int idx = j;
		for (; idx <= j + 2; ++idx)
		{
			res += arr[i][idx];
		}
		res += arr[i + 1][j + 1];
		if (res > mx)
			mx = res;

		res = 0;
		idx = j;
		for (; idx <= j + 2; ++idx)
		{
			res += arr[i + 1][idx];
		}
		res += arr[i][j + 1];
		if (res > mx)
			mx = res;
	}

	if (i + 2 <= N && j + 1 <= M)
	{
		int res = 0;
		int idx = i;
		for (; idx <= i + 2; ++idx)
		{
			res += arr[idx][j];
		}
		res += arr[i + 1][j + 1];
		if (res > mx)
			mx = res;

		res = 0;
		idx = i;
		for (; idx <= i + 2; ++idx)
		{
			res += arr[idx][j + 1];
		}
		res += arr[i + 1][j];
		if (res > mx)
			mx = res;
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%d", &arr[i][j]);

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			func1(i, j);
			func2(i, j);
			func3(i, j);
			func4(i, j);
			func5(i, j);
		}

	printf("%d\n", mx);
}