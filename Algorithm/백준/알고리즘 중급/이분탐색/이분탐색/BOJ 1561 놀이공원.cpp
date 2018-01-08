#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;


long long maxN = 0, N, M;
long long arr[10001];
int main()
{
	scanf("%lld %lld", &N, &M);
	for (int i = 1; i <= M; ++i)
	{
		long long temp;
		scanf("%lld", &temp);
		arr[i] = temp;
		if (maxN < temp)
			maxN = temp;
	}

	//sort(arr + 1, arr + M + 1);
	long long left = 1;
	long long right = N * maxN;
	if (N <= M)
	{
		printf("%d\n", N);
		return 0;
	}
	while (left <= right)
	{
		long long cnt = 0;
		long long mid = (left + right) / 2;
		for (int i = 1; i <= M; ++i)
			cnt += (mid / arr[i]);

		if (cnt >= N - M)
			right = mid - 1;
		else
			left = mid + 1;
	}

	long long cnt = 0;
	int temp = 1;
	for (int i = 1; i <= M; ++i)
	{
		cnt += (right / arr[i]);
	}
	cnt = N - cnt - M;

	long long tcnt = 0;
	for (int i = 1; i <= M; ++i)
	{
		if (!(left % arr[i]))
		{
			tcnt++;
			if (tcnt == cnt)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
}