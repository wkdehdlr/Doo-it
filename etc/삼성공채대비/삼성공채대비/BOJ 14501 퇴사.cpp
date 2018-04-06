#pragma warning(disable : 4996)
#include<cstdio>

int N;
int P[16];
int T[16];
int mx = 0;
void func(int idx, int tot)
{

	if (idx == N + 1)
	{
		 if (tot > mx)
			 mx = tot;
	}
	else
	{
		tot += P[idx];
		for (int i = idx + T[idx]; i <= N + 1; ++i)
		{
			func(i, tot);
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d %d", &T[i], &P[i]);
	}
	for (int i = 1; i <= N; ++i)
	{
		func(i, 0);
	}
	printf("%d\n", mx);
}