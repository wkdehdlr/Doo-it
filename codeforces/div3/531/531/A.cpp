#include<cstdio>


long long n;
//두 집단의 합이 최대한 비슷하게 하려면
//
int main()
{
	long long res = 0;
	scanf("%lld", &n);
	if (((n*(n + 1)) / 2) % 2)printf("1\n");
	else printf("0");
}