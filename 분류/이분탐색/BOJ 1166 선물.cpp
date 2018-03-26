#pragma warning(disable : 4996)
#include<cstdio>

int L, W, H;
long long N;

int main()
{
	scanf("%lld %d %d %d", &N, &L, &W, &H);
	double left = 0;
	double right = 2000000000;
	double mid = 0;
	double res1 = 0, res2 = 0;
	long long cnt = 0;

	while (right - left > 1E-9)
	{
		mid = (left + right) / 2;
		cnt = (long long)(L / mid) * (long long)(W / mid)* (long long)(H / mid);
		if (cnt < N)
		{
			right = mid;
		}
		else if (cnt >= N)
		{
			left = mid;
		}

		res2 = right - left;
		if (res1 == res2)
			break;
		res1 = res2;
	}
	printf("%.10lf\n", left);
}