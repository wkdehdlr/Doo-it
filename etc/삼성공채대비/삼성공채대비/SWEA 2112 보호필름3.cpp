#pragma warning(disable : 4996)
#include<cstdio>

int hang[14];
int T, D, W, K;
int mn = 0x7fffffff;

bool check()
{
	bool done = true;
	for (int j = 0; j < W; ++j)
	{
		done = true;
		for (int i = 1; i <= D - K  + 1; ++i)
		{
			done = true;
			for (int k = i; k < i + K - 1; ++k)
			{
				bool  a = (hang[k] >> j) & 1;
				bool  b = (hang[k + 1] >> j) & 1;
				if (a != b) {
					done = false;
					break;
				}
			}
			if (done)break;
		}
		if (!done)return false;
	}
	return true;
}
void DFS(int dep, int cnt)
{
	if (cnt >= mn)return;
	if (dep == D + 1)
	{
		if (check()) {
			if (mn > cnt)
				mn = cnt;
		}
	}
	else
	{
		int ori = hang[dep];
		DFS(dep + 1, cnt);

		hang[dep] = 0;
		DFS(dep + 1, cnt + 1);

		hang[dep] = (1 << W) - 1;
		DFS(dep + 1, cnt + 1);

		hang[dep] = ori;
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 1; i <= D; ++i)
		{
			int res = 0;
			for (int j = 1; j <= W; ++j)
			{
				int tmp;
				scanf("%d", &tmp);
				res <<= 1;
				res |= tmp;
			}
			hang[i] = res;
		}
		mn = 0x7fffffff;
		DFS(1, 0);
		printf("#%d %d\n", tc + 1, mn);
	}
}