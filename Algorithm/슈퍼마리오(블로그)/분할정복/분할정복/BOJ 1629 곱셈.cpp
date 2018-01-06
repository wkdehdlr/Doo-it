#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int main()
{
	long long A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);
	for (int i = 0; i < B; ++i)
	{
		A = (A % C) * (A % C);
		A %= C;
	}
	printf("%lld\n", A);
}