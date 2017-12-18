#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

#define min(a , b) a > b?b:a;

int K1, K2;
int N;

int main()
{
	scanf("%d %d", &N, &K1);

	int right = K1;
	int left = 1;


	while (left<=right)
	{
		int mid = (left + right) / 2;
		long long cnt = 0;
		for (long long i = 1; i <= N; ++i)
		{
			cnt += min(mid / i, N);
		}
		
		if (K1 <= cnt)
			right = mid-1;
		else if (cnt < K1)
			left = mid+1;
	}
	printf("%d\n", left);
}