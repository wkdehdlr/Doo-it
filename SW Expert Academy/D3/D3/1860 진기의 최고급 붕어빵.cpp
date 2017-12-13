#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int arr[11112];
int T, N, M, K;
int main()
{
	int maxN = 0;

	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < N; ++i)
		{
			int temp;
			scanf("%d", &temp);
			if (maxN < temp)
				maxN = temp;
			arr[temp]++;
		}

		bool flag = false;
		int rest_bread = 0;
		if (M == 0)
			rest_bread += K;

		for (int i = 0; i <= maxN; ++i)
		{
			if (M && (i && !(i % M)))
				rest_bread += K;

			if (arr[i])
			{
				if (rest_bread - arr[i] < 0)
				{
					flag = true;
					break;
				}
				else
					rest_bread -= arr[i];
			}

			if (M == 0)
				rest_bread += K;
		}
		if (flag)//impossible
		{
			printf("#%d Impossible\n", tc + 1);
		}
		else//possible
		{
			printf("#%d Possible\n", tc + 1);
		}

		for (int i = 0; i <= maxN; ++i)
			arr[i] = 0;
	}
}