#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int minN = 0x7fffffff;
int T, N, B;
int arr[21];

void start();
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		minN = 0x7fffffff;
		scanf("%d %d", &N, &B);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &arr[i]);
		}
		start();
		printf("#%d %d\n", tc + 1, minN);
	}
}
void start()
{
	int mask = 1 << N;
	int sum = 0;

	for (int i = 0; i < mask; ++i)
	{
		sum = 0;
		for (int j = 0; j < N; ++j)
		{
			if (i & (1 << j))
			{
				sum += arr[j + 1];
			}
		}
		if (sum >= B)
		{
			if (minN > sum - B)
				minN = sum - B;
		}
	}
}