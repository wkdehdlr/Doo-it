#pragma warning(disable : 4996) 
#include<cstdio>
using namespace std;

int N, M, T;
long long arr[100001];

int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		long long maxN = 0;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; ++i)
		{
			scanf("%lld", &arr[i]);
			if (maxN < arr[i])
				maxN = arr[i];
		}

		long long right = (maxN * M);
		long long left = 0;
		long long mid = right;

		long long total = 0;
		int flag = false;
		while (1)
		{
			for (int i = 0; i < N; ++i)
			{
				if (arr[i] < mid)
				{
					total += (mid / arr[i]);
				}
			}

			if (M <= total)
				right = mid;
			else if (total < M)
				left = mid;

			mid = (right + left) / 2;
			if (mid == left)
				break;

			total = 0;
		}
		printf("#%d %lld\n", tc + 1, right);
	}
}