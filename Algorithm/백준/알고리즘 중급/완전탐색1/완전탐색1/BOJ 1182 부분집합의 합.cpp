#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int arr[21];
int sum, N, cnt = 0;
int main()
{
	scanf("%d %d", &N, &sum);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);

	int maxn = 1 << N;
	for (int i = 1; i < maxn; ++i)
	{
		int tmp = 0;
		for (int j = 0; j < N; ++j)
		{
			if (i & (1 << j))
			{
				tmp += arr[j];
			}
		}
		if (tmp == sum)
			cnt++;
	}
	printf("%d\n", cnt);
}