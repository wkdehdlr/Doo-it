#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

long long maxN = 0, N, M;
long long arr[10001];
int main()
{
	scanf("%lld %lld", &N, &M);
	for (int i = 1; i <= M; ++i)
		scanf("%lld", &arr[i]);

	long long left = 1;
	long long right = arr[M] * N;
	
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
		if (!(left % arr[i]))
			temp = i;
	}
	printf("%d\n", temp);
}